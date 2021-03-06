// Copyright � 2008-2009 Intel Corporation
// All Rights Reserved
//
// Permission is granted to use, copy, distribute and prepare derivative works of this
// software for any purpose and without fee, provided, that the above copyright notice
// and this statement appear in all copies.  Intel makes no representations about the
// suitability of this software for any purpose.  THIS SOFTWARE IS PROVIDED "AS IS."
// INTEL SPECIFICALLY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, AND ALL LIABILITY,
// INCLUDING CONSEQUENTIAL AND OTHER INDIRECT DAMAGES, FOR THE USE OF THIS SOFTWARE,
// INCLUDING LIABILITY FOR INFRINGEMENT OF ANY PROPRIETARY RIGHTS, AND INCLUDING THE
// WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE.  Intel does not
// assume any responsibility for any errors which may appear in this software nor any
// responsibility to update it.

// Instrumentation class, to collect execution and performance stats.

#include <sstream>

#if defined(_MSC_VER)
#include <tchar.h>
#include <pdh.h>
#include <pdhmsg.h>
#endif

#include "Generic/Instrumentation.h"


// Constant number of seconds per update.
const float Instrumentation::m_secondsPerUpdate = 1.0f;

#if defined(_MSC_VER)
// Local helper class, to hold details of one processor counter.
class ProcessorCounter {
    public:
        ProcessorCounter(TCHAR* szCounterPath) : m_hQuery(NULL), m_szCounterPath(NULL) {
            BOOST_ASSERT(szCounterPath != NULL);
            size_t pathSize = _tcslen(szCounterPath) + 1;
            m_szCounterPath = new TCHAR[pathSize];
            _tcscpy_s(m_szCounterPath, pathSize, szCounterPath);
        }

        ~ProcessorCounter() {
            if (m_hQuery) {
                PdhCloseQuery(m_hQuery);
                m_hQuery = NULL;
            }

            if (m_szCounterPath) {
                delete [] m_szCounterPath;
            }
        }

        void Initialize() {
            // Create a PDH Query for reading real-time data, and add the counter to it.
            PDH_STATUS status = PdhOpenQuery(NULL, 0, &m_hQuery);

            if (status != ERROR_SUCCESS) {
                m_hQuery = NULL;
            } else {
                // If we can't add this counter to our query, it's not a very useful
                // query.  Later uses of this query will always fail.  There isn't much
                // else we can do here, so just ignore the return value.
                () PdhAddCounter(m_hQuery, m_szCounterPath, 0, &m_hCounter);
            }
        }

    public:
        HQUERY m_hQuery;
        HCOUNTER m_hCounter;

    private:
        ProcessorCounter() {};
        LPTSTR m_szCounterPath;
};
#endif

// Instrumentation class constructor.  Hook the instrumentation into the service
// manager and set up performance counters.
Instrumentation::Instrumentation() :
    m_currentFPS(0.0f),
    m_secondsSinceLastUpdate(0.0f),
    m_framesSinceLastUpdate(0),
    m_activeThreadCount(0),
    m_numCounters(0) {
#if defined(_MSC_VER)
    // Register this provider with the service manager.
    //Singletons::ServiceManager.RegisterInstrumentationProvider(this);
    // Prepare to monitor CPU performance.
    std::vector< TCHAR* >   vecCounterInstanceNames;
    PDH_STATUS              pdhStatus               = ERROR_SUCCESS;
    LPTSTR                  szObjectNameBuffer      = NULL;
    DWORD                   dwObjectNameSize        = 0;
    LPTSTR                  szCounterListBuffer     = NULL;
    DWORD                   dwCounterListSize       = 0;
    LPTSTR                  szInstanceListBuffer    = NULL;
    DWORD                   dwInstanceListSize      = 0;
    LPTSTR                  szThisInstance          = NULL;
    // The PDH library does not work as advertised under all conditions; at least some
    // of the time, it will issue "PDH_INVALID_ARGUMENT" errors on the first call, when
    // you would normally pass a NULL name pointer and expect a "PDH_MORE_DATA" return
    // and a valid size.  Working around this here by allocating a buffer that's
    // (hopefully) always "big enough" for the name.
    szObjectNameBuffer = new TCHAR[m_processorObjectNameMaxSize];
    dwObjectNameSize = m_processorObjectNameMaxSize;
    // Find the "Processor" counter object's friendly local name.  Find its size, allocate
    // a buffer, then get the name.  It has a constant index on all machines.
    pdhStatus = PdhLookupPerfNameByIndex(NULL,       // Machine name - local machine since it's NULL
                                         m_processorObjectIndex,                     // Constant index of "Processor" object
                                         szObjectNameBuffer,
                                         &dwObjectNameSize);

    if (pdhStatus == ERROR_SUCCESS) {
        // Find the buffer size for the data.
        pdhStatus = PdhEnumObjectItems(
                        NULL,                   // Real time source
                        NULL,                   // Local machine
                        szObjectNameBuffer,     // Object to enumerate
                        szCounterListBuffer,    // Pass NULL and 0
                        &dwCounterListSize,     // to get length required
                        szInstanceListBuffer,   // Buffer size
                        &dwInstanceListSize,    // Number of instances
                        PERF_DETAIL_WIZARD,     // Counter detail level
                        0);

        // Under normal conditions, the Enum call will tell us that there's more data,
        // and it will have set values for the sizes of buffers to return to it.
        // If that's not true, we'll never collect CPU data on this machine.
        if (pdhStatus == PDH_MORE_DATA) {
            // Allocate the buffers and try the call again.
            szCounterListBuffer = new TCHAR[dwCounterListSize];
            szInstanceListBuffer = new TCHAR[dwInstanceListSize];
            ASSERT((szCounterListBuffer != NULL) && (szInstanceListBuffer != NULL));

            if ((szCounterListBuffer != NULL) && (szInstanceListBuffer != NULL)) {
                pdhStatus = PdhEnumObjectItems(
                                NULL,                 // Real time source
                                NULL,                 // Local machine
                                szObjectNameBuffer,   // Object to enumerate
                                szCounterListBuffer,  // Buffer to receive counter list
                                &dwCounterListSize,
                                szInstanceListBuffer, // Buffer to receive instance list
                                &dwInstanceListSize,
                                PERF_DETAIL_WIZARD,   // Counter detail level
                                0);

                // As luck would have it, the counter we want ("% Processor Time" in
                // English, index #6) is the first one in szCounterListBuffer.  Otherwise,
                // we'd have to iterate down the list to find it.

                // Now find all instances of that counter: (0), (1), ... (_Total).
                if (pdhStatus == ERROR_SUCCESS) {
                    // Walk the instance list. The list can contain one
                    // or more null-terminated strings. The last string
                    // is followed by a second null-terminator.
                    for (szThisInstance = szInstanceListBuffer;
                            *szThisInstance != _T('\0');
                            szThisInstance += _tcslen(szThisInstance) + 1) {
                        // Object name and counter list don't change, but build
                        // a complete counter path from its various parts, which
                        // will look like "\\Processor(_Total)\\% Processor Time" etc.
                        TCHAR szFormat[] = _T("\\%s(%s)\\%s");
                        size_t pathSize = _tcslen(szFormat) +
                                          _tcslen(szObjectNameBuffer) +
                                          _tcslen(szThisInstance) +
                                          _tcslen(szCounterListBuffer) + 1;
                        // The pathSize is actually a bit bigger than it needs to be, since the
                        // format string characters (e.g. "%s") don't take any space in the
                        // final string.
                        LPTSTR szCounterPath = new TCHAR[ pathSize ];
                        _stprintf_s(szCounterPath,
                                    pathSize,
                                    szFormat,
                                    szObjectNameBuffer,             // "Processor" in English
                                    szThisInstance,                 // "0", "1", etc., as well as "_Total", in all languages
                                    szCounterListBuffer);           // "% Processor Time" in English
                        vecCounterInstanceNames.push_back(szCounterPath);
                        m_numCounters++;
                    }
                }
            }
        }
    }

    if (szCounterListBuffer != NULL) {
        delete [] szCounterListBuffer;
    }

    if (szInstanceListBuffer != NULL) {
        delete [] szInstanceListBuffer;
    }

    if (szObjectNameBuffer != NULL) {
        delete [] szObjectNameBuffer;
    }

    // Allocate array for CPU counter results.  We always have one more counter than
    // CPU, since there's a counter for "_Total" CPU usage.  If something gets really
    // wrong here, just claim one CPU.
    m_CPUCount = m_numCounters - 1;

    if (m_CPUCount <= 0) {
        m_CPUCount = 1;
    }

    m_CPUPercentCounters = new double[m_numCounters];

    for (int i = 0; i < m_numCounters; i++) {
        m_CPUPercentCounters[i] = 0.0f;
    }

    // Initialize all processor counters and capture them in the global counter vector.
    if (m_numCounters > 0) {
        std::vector< TCHAR* >::iterator iter;

        for (iter = vecCounterInstanceNames.begin(); iter != vecCounterInstanceNames.end(); ++iter) {
            ProcessorCounter* procCounter = new ProcessorCounter(*iter);
            procCounter->Initialize();
            m_vecProcessorCounters.push_back(procCounter);
        }

        // We have the counter name copied in the ProcessorCounter object, so clean up
        // the name we used here.
        TCHAR* pTemp = NULL;

        while (!vecCounterInstanceNames.empty()) {
            pTemp = vecCounterInstanceNames.back();
            vecCounterInstanceNames.pop_back();
            delete [] pTemp;
        }
    }

    // Allocate arrays for job types.
    m_pAccumulatingFrameTicks = new i64[System::Types::MAX];
    m_pLastFrameRatio = new float[System::Types::MAX];
    ASSERT((m_pAccumulatingFrameTicks != NULL) && (m_pLastFrameRatio != NULL));

    for (int i = 0; i < System::Types::MAX; i++) {
        m_pAccumulatingFrameTicks[i] = (i64)0;
        m_pLastFrameRatio[i] = 0.0f;
    }

    // Capture the first value of a tick.
    m_LastUpdateTick = __rdtsc();
    return;
#endif
}

Instrumentation::~Instrumentation() {
#if defined(_MSC_VER)
    // Delete all locally-allocated things.
    delete [] m_CPUPercentCounters;
    // Undo the registration, probably not too important since we're shutting down.
    //Singletons::ServiceManager.UnregisterInstrumentationProvider(this);

    // Clean up queries.
    while (!m_vecProcessorCounters.empty()) {
        ProcessorCounter* pCounterObject = (ProcessorCounter*)m_vecProcessorCounters.back();
        m_vecProcessorCounters.pop_back();
        delete pCounterObject;
    }

    if (m_pAccumulatingFrameTicks) {
        delete [] m_pAccumulatingFrameTicks;
    }

    if (m_pLastFrameRatio) {
        delete [] m_pLastFrameRatio;
    }

    return;
#endif
}

// Get some data periodically.  Called once per frame.
// As a side-effect, this routine retains the most recently read perf data.
//
// This code is called once per frame from the main thread.  It updates
// variables that are read later in the frame from within the graphics system.
// Thus, there is no need to make either the read or write code thread-safe.
// If this calling pattern is ever changed, make both ends thread-safe.
void Instrumentation::UpdatePeriodicData(float deltaTime) {
#if defined(_MSC_VER)
    // Only get it if it has been a while.
    m_framesSinceLastUpdate++;
    m_secondsSinceLastUpdate += deltaTime;

    if (m_secondsSinceLastUpdate > m_secondsPerUpdate) {
        m_currentFPS = (float)m_framesSinceLastUpdate / m_secondsSinceLastUpdate;
        std::vector< void* >::iterator voidIter;

        if (m_vecProcessorCounters.empty()) {
            // In the empty case (can't read counters), just return zeros for CPU percent.
            for (int i = 0; i < m_numCounters; i++) {
                m_CPUPercentCounters[i] = 0.0f;
            }
        } else {
            // Get current counter values.
            int i = 0;

            for (voidIter = m_vecProcessorCounters.begin();
                    voidIter != m_vecProcessorCounters.end();
                    ++voidIter, i++) {
                // Start with a zero, in case there's some error.
                m_CPUPercentCounters[i] = 0.0f;
                ProcessorCounter* counterInstance = (ProcessorCounter*)*voidIter;
                // Read all current counters via their handles.  If some error condition
                // has left us with a NULL query handle, the call will just fail and we'll
                // still have a zero counter this time.
                PDH_STATUS status = PdhCollectQueryData(counterInstance->m_hQuery);

                if (status == ERROR_SUCCESS) {
                    // In rare cases, PdhGetFormattedCounterValue can return bad values (<0 or >100)
                    // when called in this pattern.  If that becomes a problem, it's possible to
                    // work around the problem by adding a short sleep (e.g. 10 msec) and a second
                    // call to PdhCollectQueryData, before calling PdhGetFormattedCounterValue.
                    // In testing, we haven't seen the problem.  Any such problem that occurs on a
                    // single read will tend to not occur on the next read, so any such problem
                    // is transient enough to ignore.
                    PDH_FMT_COUNTERVALUE value;
                    // Get the actual value out of this counter query.
                    // Just pass a NULL for type, since we already know the type of this value.
                    status = PdhGetFormattedCounterValue(counterInstance->m_hCounter, PDH_FMT_DOUBLE, NULL, &value);

                    // Make sure we have valid or new data (new also implies valid), and cache it.
                    if (status == ERROR_SUCCESS &&
                            (value.CStatus == PDH_CSTATUS_NEW_DATA ||
                             value.CStatus == PDH_CSTATUS_VALID_DATA)) {
                        m_CPUPercentCounters[i] = (double)value.doubleValue;
                    }
                }
            }
        }

        // How much time did we spend on this task during this timing interval?
        // Since this is the ratio of this task's time to the length of time for
        // the frame, it can exceed one.  E.g. if we have 4 CPUs and it ran 2 threads
        // that consumed 2 CPUs for the entire frame, it would show here as 2.0x.
        i64 currentTick = __rdtsc();
        i64 tickDiff = currentTick - m_LastUpdateTick;

        // Make sure we got a legal value; can be negative if time stamp counters were read
        // on different cores that are not synchronized.
        if (tickDiff < (i64)0) {
            tickDiff = (i64)0;
        }

        m_LastUpdateTick = currentTick;

        for (int i = 0; i < System::Types::MAX; i++) {
            // Find ratio, but don't divide by zero.
            if (tickDiff == 0) {
                m_pLastFrameRatio[i] = 0.0f;
            } else {
                m_pLastFrameRatio[i] = (float)m_pAccumulatingFrameTicks[i] / (float)tickDiff;
            }

            // Clear the accumulator so we can start accumulating again.
            m_pAccumulatingFrameTicks[i] = (i64)0;
        }

        // Start counting toward next update again.
        m_secondsSinceLastUpdate = 0.0f;
        m_framesSinceLastUpdate = 0;
    }
#endif
}

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

#pragma once

#include <vector>
#include <boost/interprocess/sync/named_semaphore.hpp>
#include "Defines.h"

#pragma warning( push )
#pragma warning( disable : 4100 4189 4244 4512 4634 )

#include <tbb/task.h>
#include <tbb/task_scheduler_init.h>
#include <tbb/tbb_thread.h>
#include <tbb/spin_mutex.h>

#pragma warning( pop )

#include "Defines.h"
#include "DataTypes.h"
#include "System/ISystemTask.h"

namespace Schema {
    struct Environment;
}
class Instrumentation;

/**
 * This class uses Intel Threading Building Blocks to run tasks.
 */
class TaskManager {
public:

    /**
     * Defines an alias representing the void*.
     * This type defines the callback used for generic jobs by the <c>ITaskManager</c>.
     */
    typedef void (*JobFunction)(void*);

    /**
     * Defines an alias representing the void*.
     * This type defines the callback used for generic job completions by the <c>ITaskManager</c>.
     * ### return   the number of jobs issued by this function.
     */
    typedef unsigned int(*JobCompletionFunction)(void*);

    /**
     * Defines an alias representing the end.
     */
    typedef void (*ParallelForFunction)(void* param, unsigned int begin, unsigned int end);

    /**
     * Values that represent JobCountInstructionHints.
     * This type provides hints to the <c>GetRecommendedJobCount</c> method on the type of work
     * about to be submitted to the <c>ITaskManager</c>.
     * @sa  ITaskManager::GetRecommendedJobCount    .
     */
    enum JobCountInstructionHints {
        None, Generic, FP, SIMD_FP, SIMD_INT,
    };

    /**
     * Constructor.
     */
    TaskManager();

    /**
     * Destructor.
     */
    ~TaskManager();

    /**
     * Initialises this TaskManager.
     * Call this from the primary thread before calling any other <c>TaskManager</c> methods.
     */
    void Init(const Schema::Environment* environment);

    /**
     * Shuts down this TaskManager and frees any resources it is using.
     * Call this from the primary thread as the last <c>TaskManager</c> call.
     */
    void Shutdown();

    /**
     * Updates the periodic data described by deltaTime.
     *
     * @param   deltaTime   Time of the delta.
     */
    void updatePeriodicData(float deltaTime);

    /**
     * Issue jobs for system tasks.
     * Call this from the primary thread to schedule system work.
     *
     * @param   pTasks      an array of <c>ISystemTask</c> objects which should have their
     *                      <c>Update()</c> methods called asynchronously.
     * @param   uCount      the size of the <paramref name="pTasks"/> array.
     * @param   fDeltaTime  amount of time to be passed to each system's <c>Update</c> method.
     *
     * @sa   TaskManager::WaitForSystemTasks .
     * @sa  ISystemTask::Update                 .
     */
    void IssueJobsForSystemTasks(ISystemTask** pTasks, unsigned int uCount, float fDeltaTime);

    /**
     * Callback, called when the non standard per thread.
     * This method triggers a synchronized callback to be called once by each thread used by the
     * <c>TaskManager</c>. This method waits until all callbacks have executed.
     * Unlike the general contract for this method, this method can be safely called at
     * any time, as long as the call is made from the primary thread.
     *
     * @param   pfnCallback the function callback to execute.
     * @param   pData       a pointer to data that is passed to the callback.
     */
    virtual void NonStandardPerThreadCallback(JobFunction pfnCallback, void* pData);

    /**
     * Gets a recommended job count.
     * Call this method to determine the ideal number of tasks to submit to the <c>TaskManager</c>
     * for maximum performance.
     * <paramref name="Hints"/> is ignored and the number of active threads is always returned.
     *
     * @param   Hints   guidance on the type of work done in the jobs about to be submitted.
     * @return  the number of jobs which is optimal for the type of work specified by
     *          <paramref name="Hints"/>
     */
    virtual unsigned int GetRecommendedJobCount(JobCountInstructionHints Hints);

    /**
     * Parallel for.
     *
     * @param [in,out]  pSystemTask If non-null, the system task.
     * @param   pfnJobFunction      The pfn job function.
     * @param [in,out]  pParam      If non-null, the parameter.
     * @param   begin               The begin.
     * @param   end                 The end.
     * @param   minGrainSize        (Optional) size of the minimum grain.
     */
    virtual void ParallelFor(ISystemTask* pSystemTask,
                             ParallelForFunction pfnJobFunction, void* pParam, unsigned int begin, unsigned int end,
                             unsigned int minGrainSize = 1);

    /**
     * Wait for system tasks.
     * Call this from the primary thread to wait until specified tasks spawned with
     * <c>IssueJobsForSystemTasks</c>
     * and all of their subtasks are complete.
     *
     * @param   pTasks  an array of <c>ISystemTask</c> objects.
     * @param   uCount  the length of the <paramref name="pTasks"/> array.
     *
     * @sa   TaskManager::IssueJobsForSystemTasks    .
     */
    void WaitForSystemTasks(ISystemTask** pTasks, unsigned int uCount);

    /**
     * Gets the number of threads.
     * Call this method to get the number of threads in the thread pool which are active for running
     * work.
     *
     * @return  the number of threads being used.
     */
    inline unsigned int GetNumberOfThreads() {
        return m_uNumberOfThreads;
    };

    /**
     * Sets a number of threads.
     * This method constrains the number of threads used by the <c>TaskManager</c>.
     *
     * @param   uNumberOfThreads    the limit of the number of threads to use.
     */
    void SetNumberOfThreads(unsigned int uNumberOfThreads);

    /**
     * Query if this TaskManager is primary thread.
     *
     * @return  true if primary thread, false if not.
     */
    bool IsPrimaryThread();

    /**
     * Adds stall task.
     */
    void AddStallTask();

    /**
     * Callback, called when the system task.
     *
     * @param [in,out]  pData   If non-null, the data.
     */
    static void SystemTaskCallback(void* pData);

private:
    // TODO completely remove it when disabled.
    Instrumentation* m_instrumentation;

    tbb::tbb_thread::id m_uPrimaryThreadID;
    boost::interprocess::named_semaphore* m_hStallPoolSemaphore;
    tbb::task* m_pStallPoolParent;
    tbb::spin_mutex m_tSynchronizedCallbackMutex;

    tbb::task_scheduler_init* m_pTbbScheduler;

#if USE_MAIN_THREAD_FOR_SERIAL_TASKS_ONLY
    // IMPLEMENTATION NOTE
    // Experiments showed that temporary oversubscription during the execution
    // of primary thread bound system tasks is even beneficial rather than adverse.
    //
    // Therefore the TBB pool is created with 1 extra thread, and the master thread
    // after completing primary thread bound tasks is blocked on the Windows
    // synchronization primitive instead instead of entering wait_for_all method
    // (to prevent oversubscription during the execution of the main bulk of work)
    //
    // Doing so requires two "root" tasks instead of 1.
    tbb::empty_task* m_pRootTask;
#endif
    tbb::task* m_pSystemTasksRoot;

    bool m_bTimeToQuit;

    // requested, maximum and current number of threads in use
    int m_uMaxNumberOfThreads;
    int m_uNumberOfThreads;
    int m_uTargetNumberOfThreads;

#if defined(USE_THREAD_PROFILER)
    bool m_bTPEventsForTasks;
    bool m_bTPEventsForJobs;
    bool m_bTPEventsForSynchronize;

    __itt_event m_tSynchronizeTPEvent;
    __itt_event m_tpSystemTaskSpawn;

    /// <summary cref="TaskManager::SystemTaskSupport">
    /// This class is used by <c>TaskManager</c> to keep <c>SystemTasks</c> associated with <c>ISystemTasks</c>.
    /// </summary>
    /// <seealso cref="TaskManager::SystemTask"/>
    struct SystemTaskSupport {
        SystemTaskSupport()
            : m_bInitialized(false)
            , m_tpeSystemTask(0)
            , m_tpeSystemTaskJob(0)
            , m_tpeSystemTaskJobCompletion(0)
        {}

        bool m_bInitialized;
        __itt_event m_tpeSystemTask;
        __itt_event m_tpeSystemTaskJob;
        __itt_event m_tpeSystemTaskJobCompletion;
    };

    std::map<ISystemTask*, SystemTaskSupport> m_SupportForSystemTasks;
#endif /* USE_THREAD_PROFILER */

    typedef std::vector<ISystemTask*> SystemTasksList;

    // Holds system tasks that should be run on the primary thread
    SystemTasksList m_primaryThreadSystemTaskList;
    SystemTasksList m_tmpTaskList;

    float m_fDeltaTime;

    typedef std::vector<tbb::task::affinity_id> AffinityIDsList;
    AffinityIDsList m_affinityIDs;

    tbb::spin_mutex m_spinMutex;

    static void InitAffinityData(void* mgr);

#if defined(USE_THREAD_PROFILER)
    /// <summary cref="TaskManager::GetSupportForSystemTask">
    /// This method returns the associated <c>SystemTaskSupport</c> for the <c>ISystemTask</c>.
    /// </summary>
    /// <param name="pTask">an <c>ISystemTask</c>
    /// <returns>the associated <c>SystemTaskSupport</c> object
    SystemTaskSupport& GetSupportForSystemTask(ISystemTask* pTask);
#endif /* USE_THREAD_PROFILER */

    /**
     * Query if this TaskManager is tbb thread.
     * This method is used to determine if the calling thread is an Intel Threading Building Blocks
     * thread.
     * Due to the difficulty using the Intel Threading Building Blocks API to determine
     * this, and since no thread local storage is used as a workaround, this method
     * always returns true.
     *
     * @return  true if the calling thread is managed by Intel Theading Building Blocks, false
     *          otherwise.
     */
    static bool IsTBBThread();

    /**
     * Updates the thread pool size.
     * This method is called within <c>IssueJobsForSystemTasks</c> to update the size of TBB thread
     * pool if necessary.  The thread pool is resized by a call to <c>SetNumberOfThreads</c>.
     *
     * @sa  TaskManager::SetNumberOfThreads     .
     * @sa  TaskManager::IssueJobsForSystemTasks    .
     */
    void UpdateThreadPoolSize();
};

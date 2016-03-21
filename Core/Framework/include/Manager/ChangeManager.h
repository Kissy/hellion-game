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

#include <boost/log/sources/logger.hpp>
#include <boost/thread/tss.hpp>
#include <set>
#include <list>
#include <System/Types.h>

#include "Generic/IObserver.h"
#include "Manager/Notification.h"
#include "Manager/SubjectInfo.h"
#include "SpinMutex.h"

class ITaskManager;

/**
 * Responsible for queuing up changes requests and then issuing them to the system for modifying
 *  to the correct state.
 *
 * @sa  ChangeManager
 */
class ChangeManager : IObserver {
public:
    /**
     * Default constructor.
     */
    ChangeManager();

    /**
     * Destructor.
     */
    virtual ~ChangeManager();

    // Must be called after construction for a valid Change Manager

    // ChangeManager Functionality
    Error Register(ISubject* pInSubject, IObserver* pInObserver, System::Types::BitMask observerIdBits = System::Types::All);
    Error Register(ISubject* pInSubject, System::Changes::BitMask uInIntrestBits, IObserver* pInObserver, System::Types::BitMask observerIdBits = System::Types::All);
    Error Unregister(ISubject* pSubject, IObserver* pObserver);
    Error DistributeQueuedChanges(System::Types::BitMask Systems2BeNotified, System::Changes::BitMask ChangesToDist);

    // IObserver Functionality
    Error ChangeOccurred(ISubject* pInChangedSubject, System::Changes::BitMask uInChangedBits);
        
    /**
     * @inheritDoc
     */
    inline System::Changes::BitMask GetDesiredSystemChanges() {
        return System::Changes::All;
    }

    // Must be called before any parallel execution starts (that is
    // before changes start being accumulated in thread local lists),
    // but after the task manager has been initialized
    Error SetTaskManager(ITaskManager*);

    // Must be called before the previously set task manager has been shut down
    void ResetTaskManager();

    inline std::vector<Notification>& GetNotifyList(unsigned int tlsIndex);

protected:
    ITaskManager*       m_pTaskManager;

    struct MappedNotification {
        MappedNotification(unsigned int uID, unsigned int changedBits)
            : m_subjectID(uID)
            , m_changedBits(changedBits)
        {}

        unsigned int m_subjectID;
        unsigned int m_changedBits;
    };

    unsigned int                                     m_lastID;
    std::vector<unsigned int>                        m_indexList;
    std::vector<unsigned int>                        m_freeIDsList;
    std::vector<SubjectInfo>                m_subjectsList;
    std::list<std::vector<Notification>*>   m_notifyLists;
    std::vector<MappedNotification>         m_cumulativeNotifyList;

    boost::thread_specific_ptr<std::vector<Notification>> m_tlsNotifyList;

    DEFINE_SPIN_MUTEX(m_swUpdate);

private:
    boost::log::sources::logger logger_;

    static void InitThreadLocalData(void* mgr);
    static void FreeThreadLocalData(void* mgr);

    Error RemoveSubject(ISubject* pSubject);

    static void DistributionCallback(void* param, unsigned int begin, unsigned int end);
    void DistributeRange(unsigned int begin, unsigned int end);

    System::Types::BitMask      m_systems2BeNotified;
    System::Changes::BitMask    m_ChangesToDist;

};

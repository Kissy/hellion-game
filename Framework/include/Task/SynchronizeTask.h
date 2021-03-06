﻿// Copyright � 2008-2009 Intel Corporation
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

#include <mutex>
#include <condition_variable>
#include <tbb/task.h>

#include "Manager/TaskManager.h"
#include "DataTypes.h"

class TaskManager;

/**
 * This class is used by <c>TaskManager</c> to manage synchronized callbacks.
 *
 * @sa  tbb::task
 * @sa  TaskManager::NonStandardPerThreadCallback   .
 */
class SynchronizeTask: public tbb::task {
public:

    /**
     * Default constructor.
     */
    SynchronizeTask();

    /**
     * Gets the execute.
     *
     * @return  null if it fails, else.
     */
    tbb::task* execute();

    /**
     * Callback, called when the prepare.
     *
     * @param   fFunc           The function.
     * @param [in,out]  pParam  If non-null, the parameter.
     * @param   uCount          Number of.
     */
    static void PrepareCallback(TaskManager::JobFunction fFunc, void* pParam, unsigned int uCount) {
        m_fCallback = fFunc;
        m_pCallbackParam = pParam;
        m_lCallbacksCount = uCount;
#if defined(MSC_COMPILER)
        ResetEvent(m_hAllCallbacksInvokedEvent);
#endif
    }

public:
    static std::mutex m_allCallbacksMutex;
    static std::condition_variable m_hAllCallbacksInvokedEvent;
    static TaskManager::JobFunction m_fCallback;
    static void* m_pCallbackParam;
    static volatile long m_lCallbacksCount;

};
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

#include "Errors.h"

class ISystemObject;

/**
 * The <c>IObserver</c> interface supplies loosely coupling systems with dependency.  It
 *  facilitates a lazy behaviour where by systems only need to react to a change and facilitates
 *  dependent callback threading.
 * This interface follows the pattern commonly know as the Observer pattern,
 *  the Publish/Subscribe pattern, or the Dependents pattern.
 *
 * @sa  ISystemObject
 * @sa  ChangeManager
 */
// TODO rename EntityObserver
class IObserver {
public:
    typedef unsigned int Changes;

    /**
     * Destructor.
     * All interfaces must have virtual destructors
     */
    virtual ~IObserver() {}

    /**
     * Returns a bit mask of System Changes that this scene wants to receive changes for.  Used
     *  to inform the change control manager if this scene should be informed of the change.
     *
     * @return  A System::Changes::BitMask.
     */
    virtual inline Changes GetDesiredSystemChanges() = 0;

    /**
     * Lets the ISystemObject notify the IObserver in changes in registered aspects of interest.
     *  This method is typically called from  ChangeManager::DistributeQueuedChanges()
     *  or ISystemObject::PostChanges() depending on whether the observer registered with an
     *  ChangeManager or an ISystemObject respectively.
     *
     * @param   pSubject    A pointer to the ISystemObject interface of the component that changed.
     * @param   ChangeType  The aspects of interest that changed as defined by the supplied
     *                      ISystemObject's published interest bits. if uInChangeBits are 0, then the
     *                      subject is shutting down, and should be released.
     * @return  One of the following Error codes: Error::Success No error. Error::InvalidAddress
     *          pInSubject was NULL. Error::OutOfMemory Not enough memory is available to resolve the
     *          change.
     */
    virtual inline Error ChangeOccurred(ISystemObject* systemObject, Changes changes) = 0;

};
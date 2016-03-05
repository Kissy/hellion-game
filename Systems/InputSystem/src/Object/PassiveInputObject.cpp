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

#include "Generic/UObject.h"
#include "Scene.h"
#include "PassiveInputObject.h"

/**
 * @inheritDoc
 */
PassiveInputObject::PassiveInputObject(ISystemScene* pSystemScene, UObject* entity)
    : InputObject(pSystemScene, entity) {
}

/**
 * @inheritDoc
 */
PassiveInputObject::~PassiveInputObject() {
}

/**
 * @inheritDoc
 */
Error PassiveInputObject::initialize() {
    ASSERT(!m_bInitialized);
    
    m_bInitialized = true;
    return Errors::Success;
}

/**
 * @inheritDoc
 */
Error PassiveInputObject::ChangeOccurred(ISubject* pSubject, System::Changes::BitMask ChangeType) {
    ASSERT(m_bInitialized);

    return Errors::Success;
}

/**
 * @inheritDoc
 */
void PassiveInputObject::Update(f32 DeltaTime) {
    ASSERT(m_bInitialized);

}
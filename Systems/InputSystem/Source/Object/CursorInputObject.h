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

#include <OISB.h>

#include "Object/Object.h"
#include "Object/IGeometryObject.h"

class IEntity;

/**
 * <c>CameraInputObject</c> Implementation of the ISystemObject interface.
 * This is the Camera object created objects.
 * 
 * @sa  InputObject
 * @sa  IGeometryObject
 */
class CursorInputObject : public InputObject {
public:

    ///
    /// @inheritDoc.
    ///
    /// @param [in,out] pSystemScene    If non-null, the system scene.
    /// @param  pszName                 The name.
    ///
    CursorInputObject(ISystemScene* pSystemScene, IEntity* entity);

    ///
    /// @inheritDoc.
    ///
    ~CursorInputObject();
    
    ///
    /// @inheritDoc.
    ///
    Error initialize();
        
    ///
    /// @inheritDoc.
    ///
    void Update(f32 DeltaTime);

    ///
    /// @inheritDoc.
    ///
    System::Changes::BitMask GetPotentialSystemChanges() {
        return System::Changes::Input::Velocity;
    };

    ///
    /// @inheritDoc.
    ///
    System::Types::BitMask GetDesiredSystemChanges() {
        return System::Changes::None;
    };

    ///
    /// @inheritDoc.
    ///
    Error ChangeOccurred(ISubject* pSubject, System::Changes::BitMask ChangeType);

private:
    OIS::Mouse*         m_mouse;

};

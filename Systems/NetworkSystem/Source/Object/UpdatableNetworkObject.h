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

#include <boost/timer/timer.hpp>

#include "MathUtils.h"
#include "System.h"
#include "Generic/UObject.h"
#include "Object/IGeometryObject.h"
#include "Object/IMoveObject.h"
#include "Object/Object.h"

class ISystemScene;

/**
* Implementation of the IGraphicsObject interface. See Interfaces\Graphics.h and Interfaces\
* System.h for a definition of the class and its functions.
*
* @sa  ISystemObject
*/
class UpdatableNetworkObject : public NetworkObject, public IGeometryObject, public IMoveObject {
public:

    /**
     * @inheritDoc
     */
    UpdatableNetworkObject(ISystemScene* pSystemScene, UObject* entity);

    /**
     * @inheritDoc
     */
    ~UpdatableNetworkObject();

    /**
     * @inheritDoc
     */
    Error initialize();

    /**
     * @inheritDoc
     */
    ISystemObject::Changes GetPotentialSystemChanges() {
        return System::Changes::Physic::Position | System::Changes::Physic::Orientation
             | System::Changes::Input::Velocity | System::Changes::Input::Rotation;
    };

    /**
     * @inheritDoc
     */
    IObserver::Changes GetDesiredSystemChanges() {
        return System::Changes::None;
    };

    /**
     * @inheritDoc
     */
    Error ChangeOccurred(ISystemObject* systemObject, IObserver::Changes changes);

    /**
     * @inheritDoc
     */
    void Update(float DeltaTime);

};

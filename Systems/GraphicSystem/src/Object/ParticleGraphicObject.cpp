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

#include <OgreSceneManager.h>
#include <System/ISystemScene.h>

#include "Object/Object.h"
#include "Object/ParticleGraphicObject.h"

/**
 * @inheritDoc
 */
ParticleGraphicObject::ParticleGraphicObject(ISystemScene* pSystemScene, UObject* entity,
                                             const Schema::SystemComponent& component)
    : GraphicObject(pSystemScene, entity, component) {
    m_particleSystem = m_sceneManager->createParticleSystem("LaserShot");
    m_pNode->attachObject(m_particleSystem);
}


/**
 * @inheritDoc
 */
ParticleGraphicObject::~ParticleGraphicObject() {
}

/**
 * @inheritDoc
 */
void ParticleGraphicObject::Update(f32 DeltaTime) {

}

/**
 * @inheritDoc
 */
Error ParticleGraphicObject::ChangeOccurred(ISubject* pSubject, System::Changes::BitMask ChangeType) {


    if (ChangeType & System::Changes::Physic::Position) {
        IGeometryObject* pGeometryObject = dynamic_cast<IGeometryObject*>(pSubject);
        const Math::Vector3& Position = *pGeometryObject->GetPosition();
        m_pNode->setPosition(Position.x, Position.y, Position.z);
    }
    if (ChangeType & System::Changes::Physic::Orientation) {
        IGeometryObject* pGeometryObject = dynamic_cast<IGeometryObject*>(pSubject);
        const Math::Quaternion& Orientation = *pGeometryObject->GetOrientation();
        m_pNode->setOrientation(Orientation.w, Orientation.x, Orientation.y, Orientation.z);
    }

    return Errors::Success;
}


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

#include <OgreVector3.h>
#include <System/Types.h>
#include <schema/entity_change_generated.h>

#include "Object/Object.h"
#include "System/ISystemScene.h"

class GraphicSystem;
class GraphicScene;
class GraphicTask;

/**
 * Implementation of the IGraphicsObject interface. See Interfaces\Graphics.h and Interfaces\
 * System.h for a definition of the class and its functions.
 * 
 * @sa  GraphicObject
 * @sa  IGeometryObject
 */
class CameraGraphicObject : public GraphicObject {
    public:
        
        /**
         * @inheritDoc
         */
        CameraGraphicObject(ISystemScene& pSystemScene, UObject& entity, const Schema::SystemComponent& component);
        
        /**
         * @inheritDoc
         */
        ~CameraGraphicObject();

        /**
         * @inheritDoc
         */
        void Update(float DeltaTime);
        
        /**
         * @inheritDoc
         */
        virtual System::Changes::BitMask GetPotentialSystemChanges() {
            return System::Changes::None;    
        }
        
        /**
         * @inheritDoc
         */
        virtual IObserver::Changes GetDesiredSystemChanges() {
            return Schema::EntityChange::PhysicPosition;
        }
        
        /**
         * @inheritDoc
         */
        virtual Error ChangeOccurred(ISystemObject* systemObject, IObserver::Changes changes);

protected:

    private:

        Ogre::Camera*                       m_pCamera;
        Ogre::SceneNode*                    m_pCameraNode;
        Ogre::Viewport*                     m_pViewport;

        Ogre::Vector3                       m_vLookAt;

        enum PolygonModes {
            PolygonMode_Invalid = -1,
            PolygonMode_Points,
            PolygonMode_WireFrame,
            PolygonMode_Solid,
            PolygonMode_Count
        };

};


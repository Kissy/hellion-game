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

#include <boost/core/ignore_unused.hpp>
#include "Object/CharacterPhysicObject.h"

#include "Scene.h"
#include "Task.h"

//https://github.com/222464/EvolvedVirtualCreaturesRepo/tree/master/VirtualCreatures/Volumetric_SDL/Source/SceneObjects/Physics

CharacterPhysicObject::CharacterPhysicObject(ISystemScene& pSystemScene, UObject& entity, const Schema::SystemComponent& component)
    : ISystemObject(&pSystemScene, &entity, component)
    , m_Radius(0.0f) {
    btCollisionShape* playerShape = new btCapsuleShape(0.5, 1);
    btDefaultMotionState* fallMotionState =
            new btDefaultMotionState(btTransform(btQuaternion(1, 0, 0, 0).normalize(),
                                                 btVector3(0, 0, 0)));
    btScalar mass = 80;
    btVector3 fallInertia(0, 0, 0);
    playerShape->calculateLocalInertia(mass, fallInertia);
    btRigidBody::btRigidBodyConstructionInfo fallRigidBodyCI(mass, fallMotionState, playerShape, fallInertia);
    fallRigidBodyCI.m_friction = 0;
    fallRigidBodyCI.m_restitution = 0;
    fallRigidBodyCI.m_linearDamping = 0;
    rigidBody_ = new btRigidBody(fallRigidBodyCI);
    rigidBody_->setAngularFactor(0);
    rigidBody_->setActivationState(DISABLE_DEACTIVATION);
    GetSystemScene<PhysicScene>()->getDynamicsWorld_()->addRigidBody(rigidBody_);
}

CharacterPhysicObject::~CharacterPhysicObject() {
    delete rigidBody_;
}

Error CharacterPhysicObject::ChangeOccurred(ISystemObject* systemObject, IObserver::Changes changes) {
    if (changes & Schema::EntityChange::PhysicPosition) {
        position_ = systemObject->getMutableComponent<Schema::Components::PhysicPosition>();
        rigidBody_->getWorldTransform().setOrigin(btVector3(position_->x(), position_->y(), position_->z()));
    }
    if (changes & Schema::EntityChange::InputVelocity) {
        auto inputSystemObject = systemObject->getEntity()->GetExtension(Schema::ComponentType::InputVelocity);
        auto scalar = inputSystemObject->getComponent<Schema::Components::InputVelocity>()->scalar();
        rigidBody_->setLinearVelocity(btVector3(scalar->x(), rigidBody_->getLinearVelocity().getY(), scalar->z()));
    }
    return Errors::Success;
}

void CharacterPhysicObject::Update(float DeltaTime) {
    boost::ignore_unused(DeltaTime);

    btTransform transform;
    rigidBody_->getMotionState()->getWorldTransform(transform);
    if (transform_ == transform) {
        return;
    }

    transform_ = transform;
    bool result = position_->mutate_x(transform_.getOrigin().getX());
    position_->mutate_y(transform_.getOrigin().getY());
    position_->mutate_z(transform_.getOrigin().getZ());
    PostChanges(Schema::EntityChange::PhysicPosition);
}
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

#include <boost/bind.hpp>
#include <boost/lexical_cast.hpp>

#include "Scene.h"
#include "Generic/UObject.h"
#include "System/ISystemScene.h"
#include "ConnectNetworkObject.h"
#include "Object/IKeyboardObject.h"

/**
 * @inheritDoc
 */
ConnectNetworkObject::ConnectNetworkObject(ISystemScene* pSystemScene, UObject* entity)
    : NetworkObject(pSystemScene, entity) {
    m_propertySetters["Username"] = boost::bind(&IProperty::setString, this, System::Changes::None, &m_username, _1);
    m_propertyGetters["Username"] = boost::bind(&IProperty::getString, this, &m_username, _1);
}

/**
 * @inheritDoc
 */
ConnectNetworkObject::~ConnectNetworkObject() {
}

/**
 * @inheritDoc
 */
Error ConnectNetworkObject::initialize() {

    
    m_bInitialized = true;
    return Errors::Success;
}

/**
 * @inheritDoc
 */
Error ConnectNetworkObject::ChangeOccurred(ISystemObject* systemObject, IObserver::Changes changes) {


    if (changes & System::Changes::Input::Action) {
        const KeyboardButtonData* keyboardButtonData = dynamic_cast<IKeyboardObject*>(pSubject)->getKeyboardButtonData();
        if (keyboardButtonData->down) {
            DownstreamMessageProto downstreamMessageProto;
            downstreamMessageProto.set_type(DownstreamMessageProto::AUTHENTICATE);
            downstreamMessageProto.set_data(boost::lexical_cast<std::string>(m_username));
            GetSystemScene<NetworkScene>()->GetSystem<NetworkSystem>()->getNetworkService()->send(downstreamMessageProto);
        }
    }

    return Errors::Success;
}

/**
 * @inheritDoc
 */
void ConnectNetworkObject::Update(float DeltaTime) {

}
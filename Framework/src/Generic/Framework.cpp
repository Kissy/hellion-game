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

#include "Generic/Framework.h"

#include <flatbuffers/util.h>
#include <boost/dll.hpp>

#include "schema/environment_generated.h"

Framework::Framework() :
        m_pSceneCCM(new ChangeManager()),
        m_pObjectCCM(new ChangeManager()),
        taskManager_(new TaskManager()),
        m_pScheduler(new Scheduler(taskManager_)),
        m_pScene(nullptr),
        running_(true) {
    flatbuffers::LoadFile("Environment.bin", true, &environmentFile_);
    m_environment = Schema::GetEnvironment(environmentFile_.c_str());
}

Framework::~Framework() {
    if (m_pScene != nullptr) {
        delete m_pScene;
    }
    delete m_pScheduler;
    delete m_pSceneCCM;
    delete m_pObjectCCM;
    delete m_environment;
}

boost::system::errc::errc_t Framework::Initialize() {

    //
    // Init debugger
    // 
#ifdef DEBUG_BUILD
    //bool debuggerActive = Singletons::EnvironmentManager.Variables().GetAsBool("Framework::DebugWindow", false);
    //Singletons::Debugger.initialize(debuggerActive);
    //Singletons::Debugger.setChangeManagers(m_pSceneCCM, m_pObjectCCM);
#endif

    // TODO use constructor instead ?
    m_pScheduler->init(m_environment);

    for (auto system : *m_environment->systems()) {
        boost::filesystem::path sharedLibraryPath(boost::dll::program_location().parent_path());
        sharedLibraryPath /= system->c_str() + boost::dll::shared_library::suffix().string();
        boost::dll::shared_library systemLib(sharedLibraryPath);
        m_systemLibraries.push_back(systemLib);
        ISystem* iSystem = systemLib.get<ISystem*(Framework*)>("CreateSystem")(this);

        Schema::SystemType systemType = iSystem->GetSystemType();
        BOOST_ASSERT(m_systems.find(systemType) == m_systems.end());
        m_systems[systemType] = iSystem;
    }

    setNextScene(m_environment->startupScene()->c_str());

    //
    // Initialize resources necessary for parallel change distribution.
    //
    // TODO use constructor instead ?
    m_pObjectCCM->SetTaskManager(taskManager_);
    m_pSceneCCM->SetTaskManager(taskManager_);

    return boost::system::errc::success;
}

///
/// @inheritDoc.
///
void Framework::Shutdown() {
    //
    // Clean debugger
    //
#ifdef DEBUG_BUILD
    //Singletons::Debugger.clean();
#endif

    //
    // Free resources used for parallel execution by the change manager.
    //
    m_pObjectCCM->ResetTaskManager();
    m_pSceneCCM->ResetTaskManager();
}

///
/// @inheritDoc.
///
bool Framework::Execute() {
    // TODO
    /*if (runtimeService->isNextScene()) {
        setNextScene(runtimeService->getSceneName());
        runtimeService->setStatus(RuntimeService::Status::Running);
    }*/

    m_pScheduler->execute();
    m_pScene->update();

    return running_;
}

///
/// @inheritDoc.
///
void Framework::setNextScene(std::string nextSceneName) {
    m_pScheduler->waitForScenes();
    if (m_pScene != nullptr) {
        delete m_pScene;
    }
    m_pScene = new UScene(m_pSceneCCM, m_pObjectCCM, m_systems);
    m_pScheduler->setScene(m_pScene);
    m_pScene->init();
}

void Framework::setWindowHandle(std::size_t windowHandle) {
    windowHandle_ = windowHandle;
}

std::size_t Framework::getWindowHandle() {
    return windowHandle_;
}

void Framework::setRunning(bool running) {
    running_ = running;
}


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

//
// extern includes
//
#include "tbb/concurrent_hash_map.h"
#include "tbb/atomic.h"

class HavokPhysicsTask;
class HavokCollisionService;

#define MAIN_THREAD_IS_PART_OF_POOL 1

typedef tbb::concurrent_hash_map<u32, hkMemoryRouter*> WorkerMemoryRouterMap_t;

///////////////////////////////////////////////////////////////////////////////
/// <summary>
///   <c>HavokPhysicsSystem</c> Implementation of the ISystem interface for
///   generic HavokPhysics functionality.
/// </summary>
///////////////////////////////////////////////////////////////////////////////

class HavokPhysicsSystem : public ISystem {
    public:

        HavokPhysicsSystem(void);
        virtual ~HavokPhysicsSystem(void);

        HavokCollisionService* GetService(void) { return &m_Collision; }
        hkJobQueue* getJobQueue(void) { return m_jobQueue; }

    protected:

        /// <summary cref="HavokPhysicsSystem::GetSystemType">
        ///   Implementation of the <c>ISystem::GetSystemType</c> function.
        ///   Gets the system type for this system.
        /// </summary>
        /// <returns>System::Type - The type of the system.</returns>
        /// <seealso cref="ISystem::GetSystemType"/>
        virtual System::Type GetSystemType(void);

        /// <summary cref="HavokPhysicsSystem::Initialize">
        ///   Implementation of the <c>ISystem::Initialize</c> function.
        ///   One time initialization function for the system.
        /// </summary>
        /// <param name="Properties">Property structure array to initialize.</param>
        /// <returns>Error - Any error codes.</returns>
        /// <seealso cref="ISystem::Initialize"/>
        virtual Error Initialize(Properties::Array Properties);

        /// <summary cref="HavokPhysicsSystem::GetProperties">
        ///   Implementation of the <c>ISystem::GetProperties</c> function.
        ///   Gets the properties of this system.
        /// </summary>
        /// <param name="Properties">Property structure array to fill</param>
        /// <seealso cref="ISystem::GetProperties"/>
        virtual void GetProperties(Properties::Array& Properties);

        /// <summary cref="HavokPhysicsSystem::SetProperties">
        ///   Implementation of the <c>ISystem::SetProperties</c> function.
        ///   Sets the properties for this system.
        /// </summary>
        /// <param name="Properties">Properties to set in the system.</param>
        /// <seealso cref="ISystem::SetProperties"/>
        virtual void SetProperties(Properties::Array Properties);

        /// <summary cref="HavokPhysicsSystem::CreateScene">
        ///   Implementation of the <c>ISystem::CreateScene</c> function.
        ///   Creates a system scene for containing system objects.
        /// </summary>
        /// <returns>ISystemScene* - The newly create system scene.</returns>
        /// <seealso cref="ISystem::CreateScene"/>
        virtual ISystemScene* CreateScene(void);

        /// <summary cref="HavokPhysicsSystem::DestroyScene">
        ///   Implementation of the <c>ISystem::DestroyScene</c> function.
        ///   Destroys a system scene.
        /// </summary>
        /// <param name="pSystemScene">The scene to destroy. Any objects within are destroyed.</param>
        /// <returns>Error - Any error codes.</returns>
        /// <seealso cref="ISystem::DestroyScene"/>
        virtual Error DestroyScene(ISystemScene* pSystemScene);

    public:
        /// <summary cref="HavokPhysicsSystem::AllocateThreadResources">
        ///   Allocate resourses need to support multiple threads.
        /// </summary>
        /// <param name="pSystem">The system allocating the resources.</param>
        /// <param name="pSystem">The thread number for each thread.</param>
        static void AllocateThreadResources(HavokPhysicsSystem* pSystem);

        /// <summary cref="HavokPhysicsSystem::FreeThreadResources">
        ///   Free resourses allocated to support multiple threads.
        /// </summary>
        /// <param name="pSystem">The system allocating the resources.</param>
        static void FreeThreadResources(HavokPhysicsSystem* pSystem);

    public:
        /// <summary cref="HavokPhysicsSystem::ErrorReport">
        ///   Callback for Havok to report an error.
        ///   (See Havok documentation for more details)
        /// </summary>
        /// <param name="pString">The error string.</param>
        /// <param name="pErrorOutputObject">Pointer to the error object.</param>
        static void ErrorReport(const char* pString, void* pErrorOutputObject);

    private:

        HavokCollisionService               m_Collision;
        hkJobQueue*                         m_jobQueue;

        static u32                          s_idMainThread;
        static tbb::atomic<u32>             s_threadNumberCount;
        static WorkerMemoryRouterMap_t      s_workerMemoryRouterMap;

};


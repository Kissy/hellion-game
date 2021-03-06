cmake_minimum_required(VERSION 3.2 FATAL_ERROR)
project(GraphicSystem LANGUAGES CXX)

find_package(Ogre REQUIRED COMPONENTS Overlay Terrain)
find_package(Bullet REQUIRED)

add_library(GraphicSystem SHARED
        include/Object/AmbientLightGraphicObject.h
        include/Object/CameraGraphicObject.h
        include/Object/PhysicDebugGraphicObject.h
        include/Object/SkyboxGraphicObject.h
        include/Object/TerrainGraphicObject.h
        include/Object/Object.h
        include/GraphicSystem.h
        include/GraphicScene.h
        include/GraphicTask.h
        src/Object/AmbientLightGraphicObject.cpp
        src/Object/CameraGraphicObject.cpp
        src/Object/CursorGraphicObject.cpp
        src/Object/LightGraphicObject.cpp
        src/Object/MeshGraphicObject.cpp
        src/Object/Object.cpp
        src/Object/ParticleGraphicObject.cpp
        src/Object/PhysicDebugGraphicObject.cpp
        src/Object/SkyboxGraphicObject.cpp
        src/Object/TerrainGraphicObject.cpp
        src/GraphicSystemMain.cpp
        src/GraphicScene.cpp
        src/GraphicSystem.cpp
        src/GraphicTask.cpp
        )

target_include_directories(GraphicSystem PUBLIC
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:include>
        PRIVATE
        ${OGRE_INCLUDE_DIR}
        ${OGRE_Terrain_INCLUDE_DIR}
        ${OGRE_Overlay_INCLUDE_DIR}
        ${BULLET_INCLUDE_DIRS}
        )

target_compile_features(GraphicSystem
        PUBLIC cxx_auto_type
        PRIVATE cxx_variadic_templates
        )

target_link_libraries(GraphicSystem
        Boost
        Boost-log
        Framework
        ${OGRE_LIBRARIES}
        ${OGRE_Overlay_LIBRARIES}
        ${OGRE_Terrain_LIBRARIES}
        ${BULLET_LIBRARIES}
        )

install(TARGETS GraphicSystem
        ARCHIVE  DESTINATION lib
        LIBRARY  DESTINATION lib
        RUNTIME  DESTINATION bin)  # This is for Windows
install(DIRECTORY include/ DESTINATION include)

export(TARGETS GraphicSystem FILE GraphicSystemConfig.cmake)

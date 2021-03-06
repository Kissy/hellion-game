cmake_minimum_required(VERSION 2.8)

project("Server")

check_root_module()

add_definitions("-DHK_PLATFORM_SIM")

find_package("JNI" REQUIRED)
find_package("Havok" REQUIRED COMPONENTS "hkCompat" REQUIRED "hkSceneData" REQUIRED 
    "hkSerialize" REQUIRED "hkInternal" REQUIRED "hkGeometryUtilities" REQUIRED 
    "hkVisualize" REQUIRED "hkcdInternal" REQUIRED "hkcdCollide" REQUIRED 
    "hkpCollide" REQUIRED "hkpConstraint" REQUIRED "hkpConstraintSolver" REQUIRED 
    "hkpDynamics" REQUIRED "hkpInternal" REQUIRED "hkpUtilities" REQUIRED 
    "hkpVehicle" REQUIRED)
include_directories(${JNI_INCLUDE_DIRS} ${HAVOK_INCLUDE_DIRS})

add_project_dependency("BaseTypes")
add_project_sources("src/main/native")
add_project_sources("target/native/javah")
add_library(${PROJECT_NAME} SHARED ${${PROJECT_NAME}_HEADERS} ${${PROJECT_NAME}_SOURCES}
    "src/main/resources/${PROJECT_NAME}.def")
add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCIES})
target_link_libraries(${PROJECT_NAME} ${${PROJECT_NAME}_DEPENDENCIES}
     ${JNI_LIBRARIES} ${PROTOBUF_LIBRARIES} ${HAVOK_LIBRARIES})

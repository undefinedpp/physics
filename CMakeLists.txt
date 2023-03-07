cmake_minimum_required(VERSION 3.16)

project(physics VERSION 0.0.1 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

file(GLOB physics_headers ${CMAKE_CURRENT_SOURCE_DIR}/core/include/Physics/*/*.hpp)
file(GLOB physics_sources ${CMAKE_CURRENT_SOURCE_DIR}/core/src/*/*.cpp)

add_subdirectory(ext/SFML)

add_library(physics STATIC ${physics_headers} ${physics_sources})
target_include_directories(physics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/core/include
${CMAKE_CURRENT_SOURCE_DIR}/exit/SFML/include)
target_precompile_headers(physics PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/core/include/Physics.hpp)
target_link_libraries(physics sfml-system sfml-window sfml-graphics sfml-audio sfml-network)
target_compile_definitions(physics PUBLIC "PHYSICS_INTERNAL_TYPE=float"
    $<$<CONFIG:Debug>:PHYSICS_DEBUG>
    $<$<CONFIG:Release>:PHYSICS_RELEASE>
    $<$<CONFIG:RelWithDebInfo>:PHYSICS_DEBUG> # release with debug info still needs to be exception safe
    $<$<CONFIG:MinSizeRel>:PHYSICS_RELEASE>)

add_executable(demo demo/main.cpp)
target_link_libraries(demo physics)
cmake_minimum_required(VERSION 3.21)
project(AsciiRayTracer)

set(CMAKE_CXX_STANDARD 14)

include_directories(src/Extensions/VectorExtensions.h)

add_executable(AsciiRayTracer main.cpp)

set(SFML_STATIC_LIBRARIES TRUE)
set(SFML_DIR ${CMAKE_CURRENT_SOURCE_DIR}/libs/SFML-2.5.1/lib/cmake/SFML)
find_package(SFML COMPONENTS system window graphics audio network REQUIRED)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/libs/SFML-2.5.1/include)
target_link_libraries(AsciiRayTracer sfml-system sfml-window sfml-graphics sfml-audio)

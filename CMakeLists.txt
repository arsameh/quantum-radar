cmake_minimum_required(VERSION 3.10.0)
project(QuantumRadar VERSION 0.1.0 LANGUAGES C CXX)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB_RECURSE SOURCES "src/*.cpp")

add_executable(QuantumRadar
    src/main.cpp
    src/rules.cpp
    src/radar.cpp
    include/helpers.h
    include/rules.h
    include/radar.h
)

target_include_directories(QuantumRadar
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)
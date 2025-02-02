cmake_minimum_required(VERSION 3.10)

project(proj LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

target_include_directories(evolution_simulator
    types.h
    world/world.h
)

add_executable(evolution_simulator main.cpp)
cmake_minimum_required(VERSION 3.10)

project(evolution_simulator LANGUAGES CXX)
set(CMAKE_CXX_STANDARD 17)

add_executable(evolution_simulator main.cpp)

target_include_directories(evolution_simulator PUBLIC include)

add_subdirectory(src)


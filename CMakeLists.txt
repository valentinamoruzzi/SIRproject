cmake_minimum_required(VERSION 3.16.3) 
project(sir VERSION 0.1.0)

set(CMAKE_CXX_COMPILER g++)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD 17) 
set(CMAKE_CXX_STANDARD_REQUIRED ON) 
set(CMAKE_CXX_EXTENSIONS ON)

add_executable(sir src/sir_model.cpp src/sirdata.cpp SIRproject.cpp)
target_include_directories(sir PUBLIC "include/")
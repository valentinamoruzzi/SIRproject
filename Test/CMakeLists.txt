cmake_minimum_required(VERSION 3.16.3) 
project(sirmodel_test VERSION 0.1.0)

set(CMAKE_CXX_COMPILER g++) #versione del compilatore
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)
set(CMAKE_CXX_STANDARD_REQUIRED ON)  
set(CMAKE_CXX_STANDARD 17) # standard del linguaggio c++, versione 17

if(CMAKE_COMPILER_IS_GNUCXX)
    message(STATUS "GCC detected, adding compile flags")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -pedantic -Wall -Wextra")
endif(CMAKE_COMPILER_IS_GNUCXX)

add_executable(sirmodel_test ../src/sirmodel.cpp ../src/sirdata.cpp sirmodel_test.cpp)
target_include_directories(sirmodel_test PUBLIC "../include/")

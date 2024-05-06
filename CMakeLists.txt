cmake_minimum_required(VERSION 3.16)
project(SIRproject VERSION 0.1.0)

# abilita il supporto per i test, tra cui l'opzione BUILD_TESTING usata sotto
include(CTest)

set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# richiedi l'uso di C++17, senza estensioni non-standard offerte dal compilatore usato 
set(CMAKE_CXX_COMPILER g++-13)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS ON)

# abilita warning
string(APPEND CMAKE_CXX_FLAGS " -Wall -Wextra")

# abilita l'address sanitizer e l'undefined-behaviour sanitizer in debug mode
string(APPEND CMAKE_CXX_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")
string(APPEND CMAKE_EXE_LINKER_FLAGS_DEBUG " -fsanitize=address,undefined -fno-omit-frame-pointer")

add_executable(SIRproject main.cpp src/sirdata.cpp src/sirdata.cpp src/sirmodel.cpp src/sirmodelextended.cpp src/sirmanage.cpp src/sirprint.cpp src/sfml/plot.cpp src/sfml/area.cpp src/sfml/axis.cpp src/sfml/curve.cpp src/sfml/grid.cpp  src/sfml/line.cpp  )
target_include_directories(SIRproject PUBLIC "include/" "include/sfml")
find_package(SFML REQUIRED COMPONENTS window system graphics) #serve a me che ho mac
target_link_libraries(SIRproject PUBLIC sfml-window sfml-system sfml-graphics)




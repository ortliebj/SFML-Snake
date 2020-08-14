cmake_minimum_required(VERSION 3.16)

project(snake)

## If you want to link SFML statically
# set(SFML_STATIC_LIBRARIES TRUE)

## In most cases better set in the CMake cache
# set(SFML_DIR "<sfml root prefix>/lib/cmake/SFML")

set (CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics audio window REQUIRED)
add_executable(snake main.cpp Snake.cpp Food.cpp)# Game.cpp)
target_link_libraries(snake sfml-graphics sfml-audio sfml-window)
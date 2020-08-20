cmake_minimum_required(VERSION 3.16)

project(snake)

set (CMAKE_CXX_STANDARD 11)

find_package(SFML 2.5 COMPONENTS graphics audio window REQUIRED)
add_executable(snake main.cpp Snake.cpp Food.cpp Game.cpp GameController.cpp)
target_link_libraries(snake sfml-graphics sfml-system sfml-window)
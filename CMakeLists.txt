cmake_minimum_required(VERSION 3.15)
project(mage)

set(CMAKE_CXX_STANDARD 14)

add_executable(mage main.cpp gapbuffer.cpp gapbuffer.h file.cpp file.h window.cpp window.h)
set(CMAKE_CXX_FLAGS "-lncurses")


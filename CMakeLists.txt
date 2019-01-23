# cmake_minimum_required(VERSION <specify CMake version here>)
project(test)

set(CMAKE_CXX_STANDARD 14)


add_executable(test main.cpp)
add_executable(xunlei TestXunlei.cpp)

link_libraries("E:\\cproject\\test\\sayHello.dll")

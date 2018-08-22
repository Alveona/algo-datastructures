cmake_minimum_required(VERSION 3.9)
project(data_s)

set(CMAKE_CXX_STANDARD 11)

add_executable(data_s main.cpp stack.cpp stack.h singlylinkedlist.cpp singlylinkedlist.h Node.cpp Node.h)
cmake_minimum_required(VERSION 3.8)
project(learn)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp list/linear_list.h list/array_list.h list/chain_list.h experments/one.cpp experments/two.h)
add_executable(learn ${SOURCE_FILES})
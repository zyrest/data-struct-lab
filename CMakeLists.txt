cmake_minimum_required(VERSION 3.8)
project(learn)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp list/linear_list.h list/array_list.h list/chain_list.h experments/one.cpp experments/two.h matrix/tridiagonal_matrix.h matrix/lowdiagonal_matrix.h matrix/sparse_matrix.h stack/arrayStack.h stack/stack.h queue/queue.h queue/array_queue.h)
add_executable(learn ${SOURCE_FILES})
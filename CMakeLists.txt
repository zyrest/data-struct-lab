cmake_minimum_required(VERSION 3.8)
project(learn)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp experments/recursion.cpp experments/sort.h stack/stack.h queue/queue.h experments/cal_maze.cpp dict/hash_table.h experments/huffman_tree.cpp graph/graph.h tree/tree.h heap/heap.h list/list.h matrix/matrix.h experments/min_tree.cpp)
add_executable(learn ${SOURCE_FILES})
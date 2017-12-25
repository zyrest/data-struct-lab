cmake_minimum_required(VERSION 3.8)
project(learn)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp experments/recursion.cpp experments/sort.h matrix/tridiagonal_matrix.h matrix/lowdiagonal_matrix.h matrix/sparse_matrix.h stack/stack.h queue/queue.h experments/cal_maze.cpp dict/hash_table.h tree/binary_tree.h experments/huffman_tree.cpp tree/binary_search_tree.h graph/graph.h tree/tree.h heap/heap.h list/list.h)
add_executable(learn ${SOURCE_FILES})
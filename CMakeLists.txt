cmake_minimum_required(VERSION 3.6)
project(Graphs)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES Array.cpp Array.h ArrayMatrix.cpp ArrayMatrix.h arraysearch.h arraysort.h Graph.cpp Graph.h LinkedList.cpp LinkedList.h MatrixElement.cpp MatrixElement.h reachability.cpp ArgumentManager.h StackLinkedList.cpp StackLinkedList.h HashTable.cpp HashTable.h)
add_executable(Graphs ${SOURCE_FILES})
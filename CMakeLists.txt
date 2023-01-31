cmake_minimum_required(VERSION 3.12)
project(DSA)
aux_source_directory(. DIR_SRC)
add_executable(DSA List/List.h List/List.hpp Queue/Queue.h Queue/Queue.hpp
        Stack/Stack.h Stack/Stack.hpp Tree/Tree.h Tree/Tree.hpp main.cpp)







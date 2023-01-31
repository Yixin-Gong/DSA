cmake_minimum_required(VERSION 2.8)

project(DSA)

aux_source_directory(. DIR_SRC)

add_subdirectory(List)
add_subdirectory(Queue)
add_subdirectory(Stack)
add_subdirectory(Tree)

add_executable(DSA main.cpp)

target_link_libraries(DSA List)
target_link_libraries(DSA Queue)
target_link_libraries(DSA Stack)
target_link_libraries(DSA Tree)






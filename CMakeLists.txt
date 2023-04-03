cmake_minimum_required(VERSION 3.12)
project(DSA)
set(SOURCES
        src/main.cpp)
add_executable(DSA ${SOURCES})
target_include_directories(DSA
        PRIVATE
        ${PROJECT_SOURCE_DIR}/include
        )





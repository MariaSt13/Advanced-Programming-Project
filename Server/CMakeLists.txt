cmake_minimum_required(VERSION 3.8)
project(ex4)

set(CMAKE_CXX_STANDARD 98)


set(SOURCE_FILES Server.cpp Server.h ReadDefinitionFile.h ReadDefinitionFile.cpp)
add_executable(server ${SOURCE_FILES} main.cpp)

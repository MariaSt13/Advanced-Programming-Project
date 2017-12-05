cmake_minimum_required(VERSION 3.8)
project(ex4)

set(CMAKE_CXX_STANDARD 98)


set(SOURCE_FILES Server.cpp Server.h)
#set(TEST_FILES test/ConsoleBoardTest.cpp test/ConsoleBoardTest.h test/StandardGameLogicTest.cpp test/PointTest.cpp test/AIPlayerTest.cpp)
add_executable(server ${SOURCE_FILES} main.cpp)
#add_executable(testing ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
#target_link_libraries(testing gmock gmock_main gtest gtest_main)
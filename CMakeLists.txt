cmake_minimum_required(VERSION 3.8)
project(exam1)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES Board.cpp Board.h ConsoleBoard.cpp ConsoleBoard.h Player.h HumanLocalPlayer.cpp HumanLocalPlayer.h GameLogic.h StandardGameLogic.cpp StandardGameLogic.h ReversiGame.cpp ReversiGame.h Point.cpp Point.h Menu.cpp AIPlayer.cpp AIPlayer.h Menu.h)
set(TEST_FILES test/ConsoleBoardTest.cpp test/ConsoleBoardTest.h test/StandardGameLogicTest.cpp test/StandardGameLogicTest.h test/PointTest.cpp test/AIPlayerTest.cpp)
add_executable(exam1 ${SOURCE_FILES} main.cpp)
add_executable(testing ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
target_link_libraries(testing gmock gmock_main gtest gtest_main)
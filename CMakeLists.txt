cmake_minimum_required(VERSION 3.8)
project(exam1)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES main.cpp Board.cpp Board.h ConsoleBoard.cpp ConsoleBoard.h Player.h HumanLocalPlayer.cpp HumanLocalPlayer.h GameLogic.h StandardGameLogic.cpp StandardGameLogic.h ReversiGame.cpp ReversiGame.h Point.cpp Point.h Menu.cpp AIPlayer.cpp AIPlayer.h Menu.h test/gtestMain.cpp)
add_executable(exam1 ${SOURCE_FILES})
target_link_libraries(exam1 gtest gtest_main)
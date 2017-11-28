cmake_minimum_required(VERSION 3.8)
project(exam1)

set(CMAKE_CXX_STANDARD 98)

set(SOURCE_FILES main.cpp Board.cpp Board.h ConsoleBoard.cpp ConsoleBoard.h Player.h HumanLocalPlayer.cpp HumanLocalPlayer.h GameLogic.h StandardGameLogic.cpp StandardGameLogic.h ReversiGame.cpp ReversiGame.h Point.cpp Point.h)
add_executable(exam1 ${SOURCE_FILES})
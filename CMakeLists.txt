cmake_minimum_required(VERSION 3.8)
project(Advanced_Programming_Project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        Board.cpp
        Board.h
        ConsoleBoard.cpp
        ConsoleBoard.h
        GameLogic.h
        HumanLocalPlayer.cpp
        HumanLocalPlayer.h
        main.cpp
        Player.h
        Point.cpp
        Point.h
        ReversiGame.cpp
        ReversiGame.h
        StandardGameLogic.cpp
        StandardGameLogic.h AlPlayer.cpp AlPlayer.h)

add_executable(Advanced_Programming_Project ${SOURCE_FILES})
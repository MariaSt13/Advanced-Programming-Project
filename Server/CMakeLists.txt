cmake_minimum_required(VERSION 3.8)
project(ex4)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS -pthread)

set(SOURCE_FILES Server.cpp Server.h ReadDefinitionFile.h ReadDefinitionFile.cpp CommandsManager.cpp CommandsManager.h
        Command.h Command.cpp StartCommand.cpp StartCommand.h ListGamesCommand.cpp ListGamesCommand.h JoinCommand.cpp JoinCommand.h
        PlayCommand.cpp PlayCommand.h CloseCommand.cpp CloseCommand.h Game.cpp Game.h GameManager.cpp GameManager.h
        GameListManager.cpp GameListManager.h ServerDataManager.cpp ServerDataManager.h)
add_executable(server ${SOURCE_FILES} main.cpp)

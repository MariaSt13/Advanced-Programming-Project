cmake_minimum_required(VERSION 3.8)
project(ex4)

set(CMAKE_CXX_STANDARD 98)
set(CMAKE_CXX_FLAGS -pthread)

set(SOURCE_FILES Server.cpp Server.h ReadDefinitionFile.h ReadDefinitionFile.cpp CommandsManager.cpp CommandsManager.h
        Command.h StartCommand.cpp StartCommand.h ListGamesCommand.cpp ListGamesCommand.h JoinCommand.cpp JoinCommand.h
        Game.cpp Game.h GameManager.cpp GameManager.h GameListManager.cpp GameListManager.h
        ServerDataManager.cpp ServerDataManager.h)
<<<<<<< HEAD
add_executable(server ${SOURCE_FILES} main.cpp)
=======
add_executable(server ${SOURCE_FILES} main.cpp)
>>>>>>> a336b15a087674cdbaaffef33fd9cea2f6023b81

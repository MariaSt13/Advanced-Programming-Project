cmake_minimum_required(VERSION 3.8)
project(exam1)

set(CMAKE_CXX_STANDARD 98)
add_subdirectory(lib/googletest-release-1.8.0)
include_directories(lib/googletest-release-1.8.0/googletest/include)
include_directories(lib/googletest-release-1.8.0/googlemock/include)

set(SOURCE_FILES Board.cpp Board.h Player.h HumanLocalPlayer.cpp HumanLocalPlayer.h GameLogic.h StandardGameLogic.cpp
        StandardGameLogic.h ReversiGame.cpp ReversiGame.h Point.cpp Point.h Menu.cpp AIPlayer.cpp AIPlayer.h Menu.h RemotePlayer.cpp RemotePlayer.h
        Client.cpp Client.h ReadDefinitionFile.cpp ReadDefinitionFile.h clientDefinitionFile.txt UserInterface.h ConsoleInterface.cpp ConsoleInterface.h
        CommandMenu.cpp CommandMenu.h)

set(TEST_FILES test/BoardTest.cpp test/BoardTest.h test/StandardGameLogicTest.cpp test/PointTest.cpp
        test/AIPlayerTest.cpp test/ReadDefinitionFileTest.cpp)
add_executable(cleint ${SOURCE_FILES} main.cpp)
add_executable(Mytesting ${SOURCE_FILES} ${TEST_FILES} test/gtest_main.cpp)
target_link_libraries(Mytesting gmock gmock_main gtest gtest_main)
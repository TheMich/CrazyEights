cmake_minimum_required(VERSION 4.2)
project(Crazy8)

set(CMAKE_CXX_STANDARD 26)
find_package(fmt CONFIG REQUIRED)
add_executable(Crazy8 main.cpp
        Random.h
        Game.cpp
        Game.h
        Deck.cpp
        Deck.h)

target_link_libraries(Crazy8 PRIVATE fmt::fmt)
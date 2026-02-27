cmake_minimum_required(VERSION 4.1)
project(project1_spidersol)

set(CMAKE_CXX_STANDARD 20)

add_executable(project1_spidersol src/main.cpp
        src/Deck.h
        src/LinkedList.h
        src/LinkedList.cpp)

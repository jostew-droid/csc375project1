cmake_minimum_required(VERSION 4.1)
project(SoltaireSpider)

set(CMAKE_CXX_STANDARD 20)

add_executable(SoltaireSpider main.cpp
        Node.cpp
        Node.h
        Stack.cpp
        Stack.h
        Queue.cpp
        Queue.h
        LinkedList.cpp
        LinkedList.h
        Card.cpp
        Card.h
        Deck.cpp
        Deck.h)

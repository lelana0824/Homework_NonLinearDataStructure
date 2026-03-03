cmake_minimum_required(VERSION 4.0)
project(Homework_NonLinearDataStructure)

set(CMAKE_CXX_STANDARD 20)

add_executable(Homework_NonLinearDataStructure main.cpp
        Container/Node.h
        Container/BinarySearchTree.cpp
        Container/BinarySearchTree.h
        PlayerInfo.h
        Container/Pair.h)

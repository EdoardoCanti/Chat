cmake_minimum_required(VERSION 3.27)
project(Lab_Programmazione)

set(CMAKE_CXX_STANDARD 17)

add_executable(Lab_Programmazione main.cpp
        User.h
        User.cpp
        Message.cpp
        Message.h
        Chat.h
        Chat.cpp
        SystemRegister.h
        SystemRegister.cpp
        User.cpp
        GroupChat.h
        GroupChat.cpp)

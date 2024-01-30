cmake_minimum_required(VERSION 3.27)
project(Lab_Programmazione)
add_subdirectory(test)
set(CMAKE_CXX_STANDARD 17)

set(SOURCE_FILES User.h
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

add_executable(Lab_Programmazione main.cpp)
add_library(core ${SOURCE_FILES})
target_link_libraries(Lab_Programmazione core)

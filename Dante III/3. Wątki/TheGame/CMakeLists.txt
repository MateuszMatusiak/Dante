cmake_minimum_required(VERSION 3.16)
project(TheGame)

set(CMAKE_CXX_STANDARD 14)

ADD_LIBRARY(LibsModule main.cpp)

target_link_libraries(LibsModule -lpthread -lrt -lm -lncursesw)

add_executable(TheGame main.cpp Map.cpp Map.h)
target_link_libraries(TheGame LibsModule)


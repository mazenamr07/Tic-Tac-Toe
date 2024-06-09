cmake_minimum_required(VERSION 3.28)
project(Tic_Tac_Toe)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tic_Tac_Toe src/main.cpp
        src/util.cpp
        include/util.h
)
target_link_libraries(Tic_Tac_Toe -static)
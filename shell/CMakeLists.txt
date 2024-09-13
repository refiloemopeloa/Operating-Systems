cmake_minimum_required(VERSION 3.22)
project(Code C)

set(CMAKE_C_STANDARD 11)

# Add the executable
add_executable(shell shell.c
        file_handling.h
        print.h)



#end
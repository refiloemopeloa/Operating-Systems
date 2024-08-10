cmake_minimum_required(VERSION 3.22)
project(Code C)

set(CMAKE_C_STANDARD 11)

# Add the executable
add_executable(cpu cpu.c)
add_executable(hello_world hello_world.c)
add_executable(arguments arguments.c)


#end
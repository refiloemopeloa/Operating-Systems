cmake_minimum_required(VERSION 3.22)
project(Code C)

set(CMAKE_C_STANDARD 11)

# Add the executable
add_executable(cpu cpu.c)
add_executable(hello_world hello_world.c)
add_executable(arguments arguments.c)
add_executable(fork fork.c)
add_executable(wait wait.c)
add_executable(wait-return wait-return.c)
add_executable(zombies zombies.c)
add_executable(clone-process clone-process.c)
add_executable(catch-signal catch-signal.c)
add_executable(catch-throw catch-throw.c)
add_executable(catch-test catch-test.c)
add_executable(loop-fork loop-fork.c)



#end
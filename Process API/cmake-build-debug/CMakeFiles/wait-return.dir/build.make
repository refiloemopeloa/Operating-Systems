# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3010A - OS/Labs/1/Lab1Files/Operating-Systems/Process API"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3010A - OS/Labs/1/Lab1Files/Operating-Systems/Process API/cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/wait-return.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/wait-return.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/wait-return.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/wait-return.dir/flags.make

CMakeFiles/wait-return.dir/wait-return.c.o: CMakeFiles/wait-return.dir/flags.make
CMakeFiles/wait-return.dir/wait-return.c.o: ../wait-return.c
CMakeFiles/wait-return.dir/wait-return.c.o: CMakeFiles/wait-return.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3010A - OS/Labs/1/Lab1Files/Operating-Systems/Process API/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/wait-return.dir/wait-return.c.o"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/wait-return.dir/wait-return.c.o -MF CMakeFiles/wait-return.dir/wait-return.c.o.d -o CMakeFiles/wait-return.dir/wait-return.c.o -c "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3010A - OS/Labs/1/Lab1Files/Operating-Systems/Process API/wait-return.c"

CMakeFiles/wait-return.dir/wait-return.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/wait-return.dir/wait-return.c.i"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3010A - OS/Labs/1/Lab1Files/Operating-Systems/Process API/wait-return.c" > CMakeFiles/wait-return.dir/wait-return.c.i

CMakeFiles/wait-return.dir/wait-return.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/wait-return.dir/wait-return.c.s"
	/usr/bin/gcc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3010A - OS/Labs/1/Lab1Files/Operating-Systems/Process API/wait-return.c" -o CMakeFiles/wait-return.dir/wait-return.c.s

# Object files for target wait-return
wait__return_OBJECTS = \
"CMakeFiles/wait-return.dir/wait-return.c.o"

# External object files for target wait-return
wait__return_EXTERNAL_OBJECTS =

wait-return: CMakeFiles/wait-return.dir/wait-return.c.o
wait-return: CMakeFiles/wait-return.dir/build.make
wait-return: CMakeFiles/wait-return.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3010A - OS/Labs/1/Lab1Files/Operating-Systems/Process API/cmake-build-debug/CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable wait-return"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/wait-return.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/wait-return.dir/build: wait-return
.PHONY : CMakeFiles/wait-return.dir/build

CMakeFiles/wait-return.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/wait-return.dir/cmake_clean.cmake
.PHONY : CMakeFiles/wait-return.dir/clean

CMakeFiles/wait-return.dir/depend:
	cd "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3010A - OS/Labs/1/Lab1Files/Operating-Systems/Process API/cmake-build-debug" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3010A - OS/Labs/1/Lab1Files/Operating-Systems/Process API" "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3010A - OS/Labs/1/Lab1Files/Operating-Systems/Process API" "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3010A - OS/Labs/1/Lab1Files/Operating-Systems/Process API/cmake-build-debug" "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3010A - OS/Labs/1/Lab1Files/Operating-Systems/Process API/cmake-build-debug" "/mnt/c/Users/matth/OneDrive - University of Witwatersrand/School/2024/COMS/3010A - OS/Labs/1/Lab1Files/Operating-Systems/Process API/cmake-build-debug/CMakeFiles/wait-return.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/wait-return.dir/depend


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
CMAKE_SOURCE_DIR = /data/home/whx/develop/cpp/section_2/49.externC浅析

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /data/home/whx/develop/cpp/section_2/49.externC浅析/build

# Include any dependencies generated for this target.
include CMakeFiles/main.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main.dir/flags.make

CMakeFiles/main.dir/49.externC浅析.cpp.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/49.externC浅析.cpp.o: ../49.externC浅析.cpp
CMakeFiles/main.dir/49.externC浅析.cpp.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/home/whx/develop/cpp/section_2/49.externC浅析/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main.dir/49.externC浅析.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main.dir/49.externC浅析.cpp.o -MF CMakeFiles/main.dir/49.externC浅析.cpp.o.d -o CMakeFiles/main.dir/49.externC浅析.cpp.o -c /data/home/whx/develop/cpp/section_2/49.externC浅析/49.externC浅析.cpp

CMakeFiles/main.dir/49.externC浅析.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main.dir/49.externC浅析.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /data/home/whx/develop/cpp/section_2/49.externC浅析/49.externC浅析.cpp > CMakeFiles/main.dir/49.externC浅析.cpp.i

CMakeFiles/main.dir/49.externC浅析.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main.dir/49.externC浅析.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /data/home/whx/develop/cpp/section_2/49.externC浅析/49.externC浅析.cpp -o CMakeFiles/main.dir/49.externC浅析.cpp.s

CMakeFiles/main.dir/49.附加1test.c.o: CMakeFiles/main.dir/flags.make
CMakeFiles/main.dir/49.附加1test.c.o: ../49.附加1test.c
CMakeFiles/main.dir/49.附加1test.c.o: CMakeFiles/main.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/data/home/whx/develop/cpp/section_2/49.externC浅析/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/main.dir/49.附加1test.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/main.dir/49.附加1test.c.o -MF CMakeFiles/main.dir/49.附加1test.c.o.d -o CMakeFiles/main.dir/49.附加1test.c.o -c /data/home/whx/develop/cpp/section_2/49.externC浅析/49.附加1test.c

CMakeFiles/main.dir/49.附加1test.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/main.dir/49.附加1test.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /data/home/whx/develop/cpp/section_2/49.externC浅析/49.附加1test.c > CMakeFiles/main.dir/49.附加1test.c.i

CMakeFiles/main.dir/49.附加1test.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/main.dir/49.附加1test.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /data/home/whx/develop/cpp/section_2/49.externC浅析/49.附加1test.c -o CMakeFiles/main.dir/49.附加1test.c.s

# Object files for target main
main_OBJECTS = \
"CMakeFiles/main.dir/49.externC浅析.cpp.o" \
"CMakeFiles/main.dir/49.附加1test.c.o"

# External object files for target main
main_EXTERNAL_OBJECTS =

main: CMakeFiles/main.dir/49.externC浅析.cpp.o
main: CMakeFiles/main.dir/49.附加1test.c.o
main: CMakeFiles/main.dir/build.make
main: CMakeFiles/main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/data/home/whx/develop/cpp/section_2/49.externC浅析/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable main"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main.dir/build: main
.PHONY : CMakeFiles/main.dir/build

CMakeFiles/main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main.dir/clean

CMakeFiles/main.dir/depend:
	cd /data/home/whx/develop/cpp/section_2/49.externC浅析/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /data/home/whx/develop/cpp/section_2/49.externC浅析 /data/home/whx/develop/cpp/section_2/49.externC浅析 /data/home/whx/develop/cpp/section_2/49.externC浅析/build /data/home/whx/develop/cpp/section_2/49.externC浅析/build /data/home/whx/develop/cpp/section_2/49.externC浅析/build/CMakeFiles/main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main.dir/depend


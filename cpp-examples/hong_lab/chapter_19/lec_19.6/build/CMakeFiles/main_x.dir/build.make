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
CMAKE_SOURCE_DIR = /home/keti/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/keti/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/build

# Include any dependencies generated for this target.
include CMakeFiles/main_x.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main_x.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main_x.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_x.dir/flags.make

CMakeFiles/main_x.dir/main_x.cpp.o: CMakeFiles/main_x.dir/flags.make
CMakeFiles/main_x.dir/main_x.cpp.o: ../main_x.cpp
CMakeFiles/main_x.dir/main_x.cpp.o: CMakeFiles/main_x.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keti/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main_x.dir/main_x.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_x.dir/main_x.cpp.o -MF CMakeFiles/main_x.dir/main_x.cpp.o.d -o CMakeFiles/main_x.dir/main_x.cpp.o -c /home/keti/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/main_x.cpp

CMakeFiles/main_x.dir/main_x.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_x.dir/main_x.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keti/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/main_x.cpp > CMakeFiles/main_x.dir/main_x.cpp.i

CMakeFiles/main_x.dir/main_x.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_x.dir/main_x.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keti/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/main_x.cpp -o CMakeFiles/main_x.dir/main_x.cpp.s

# Object files for target main_x
main_x_OBJECTS = \
"CMakeFiles/main_x.dir/main_x.cpp.o"

# External object files for target main_x
main_x_EXTERNAL_OBJECTS =

main_x: CMakeFiles/main_x.dir/main_x.cpp.o
main_x: CMakeFiles/main_x.dir/build.make
main_x: /usr/lib/x86_64-linux-gnu/libtbb.so.12.5
main_x: CMakeFiles/main_x.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/keti/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main_x"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_x.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_x.dir/build: main_x
.PHONY : CMakeFiles/main_x.dir/build

CMakeFiles/main_x.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_x.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_x.dir/clean

CMakeFiles/main_x.dir/depend:
	cd /home/keti/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keti/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6 /home/keti/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6 /home/keti/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/build /home/keti/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/build /home/keti/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/build/CMakeFiles/main_x.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_x.dir/depend


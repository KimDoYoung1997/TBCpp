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
CMAKE_SOURCE_DIR = /home/keti/cpp-workspace/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/keti/cpp-workspace/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/build

# Include any dependencies generated for this target.
include CMakeFiles/main_y.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/main_y.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/main_y.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main_y.dir/flags.make

CMakeFiles/main_y.dir/main_y.cpp.o: CMakeFiles/main_y.dir/flags.make
CMakeFiles/main_y.dir/main_y.cpp.o: ../main_y.cpp
CMakeFiles/main_y.dir/main_y.cpp.o: CMakeFiles/main_y.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keti/cpp-workspace/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main_y.dir/main_y.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/main_y.dir/main_y.cpp.o -MF CMakeFiles/main_y.dir/main_y.cpp.o.d -o CMakeFiles/main_y.dir/main_y.cpp.o -c /home/keti/cpp-workspace/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/main_y.cpp

CMakeFiles/main_y.dir/main_y.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main_y.dir/main_y.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keti/cpp-workspace/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/main_y.cpp > CMakeFiles/main_y.dir/main_y.cpp.i

CMakeFiles/main_y.dir/main_y.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main_y.dir/main_y.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keti/cpp-workspace/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/main_y.cpp -o CMakeFiles/main_y.dir/main_y.cpp.s

# Object files for target main_y
main_y_OBJECTS = \
"CMakeFiles/main_y.dir/main_y.cpp.o"

# External object files for target main_y
main_y_EXTERNAL_OBJECTS =

main_y: CMakeFiles/main_y.dir/main_y.cpp.o
main_y: CMakeFiles/main_y.dir/build.make
main_y: /usr/lib/x86_64-linux-gnu/libtbb.so.12.5
main_y: CMakeFiles/main_y.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/keti/cpp-workspace/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main_y"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main_y.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main_y.dir/build: main_y
.PHONY : CMakeFiles/main_y.dir/build

CMakeFiles/main_y.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main_y.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main_y.dir/clean

CMakeFiles/main_y.dir/depend:
	cd /home/keti/cpp-workspace/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keti/cpp-workspace/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6 /home/keti/cpp-workspace/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6 /home/keti/cpp-workspace/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/build /home/keti/cpp-workspace/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/build /home/keti/cpp-workspace/TBCpp/cpp-examples/hong_lab/chapter_19/lec_19.6/build/CMakeFiles/main_y.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main_y.dir/depend


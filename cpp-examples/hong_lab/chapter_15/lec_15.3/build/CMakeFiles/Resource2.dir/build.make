# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
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
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_15/lec_15.3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_15/lec_15.3/build

# Include any dependencies generated for this target.
include CMakeFiles/Resource2.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Resource2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Resource2.dir/flags.make

CMakeFiles/Resource2.dir/Resource2.cpp.o: CMakeFiles/Resource2.dir/flags.make
CMakeFiles/Resource2.dir/Resource2.cpp.o: ../Resource2.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_15/lec_15.3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Resource2.dir/Resource2.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Resource2.dir/Resource2.cpp.o -c /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_15/lec_15.3/Resource2.cpp

CMakeFiles/Resource2.dir/Resource2.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Resource2.dir/Resource2.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_15/lec_15.3/Resource2.cpp > CMakeFiles/Resource2.dir/Resource2.cpp.i

CMakeFiles/Resource2.dir/Resource2.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Resource2.dir/Resource2.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_15/lec_15.3/Resource2.cpp -o CMakeFiles/Resource2.dir/Resource2.cpp.s

# Object files for target Resource2
Resource2_OBJECTS = \
"CMakeFiles/Resource2.dir/Resource2.cpp.o"

# External object files for target Resource2
Resource2_EXTERNAL_OBJECTS =

libResource2.a: CMakeFiles/Resource2.dir/Resource2.cpp.o
libResource2.a: CMakeFiles/Resource2.dir/build.make
libResource2.a: CMakeFiles/Resource2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_15/lec_15.3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libResource2.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Resource2.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Resource2.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Resource2.dir/build: libResource2.a

.PHONY : CMakeFiles/Resource2.dir/build

CMakeFiles/Resource2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Resource2.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Resource2.dir/clean

CMakeFiles/Resource2.dir/depend:
	cd /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_15/lec_15.3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_15/lec_15.3 /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_15/lec_15.3 /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_15/lec_15.3/build /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_15/lec_15.3/build /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_15/lec_15.3/build/CMakeFiles/Resource2.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Resource2.dir/depend


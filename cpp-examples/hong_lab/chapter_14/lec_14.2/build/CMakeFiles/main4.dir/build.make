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
CMAKE_SOURCE_DIR = /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_14/lec_14.2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_14/lec_14.2/build

# Include any dependencies generated for this target.
include CMakeFiles/main4.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/main4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/main4.dir/flags.make

CMakeFiles/main4.dir/main4.cpp.o: CMakeFiles/main4.dir/flags.make
CMakeFiles/main4.dir/main4.cpp.o: ../main4.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_14/lec_14.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/main4.dir/main4.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/main4.dir/main4.cpp.o -c /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_14/lec_14.2/main4.cpp

CMakeFiles/main4.dir/main4.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/main4.dir/main4.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_14/lec_14.2/main4.cpp > CMakeFiles/main4.dir/main4.cpp.i

CMakeFiles/main4.dir/main4.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/main4.dir/main4.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_14/lec_14.2/main4.cpp -o CMakeFiles/main4.dir/main4.cpp.s

# Object files for target main4
main4_OBJECTS = \
"CMakeFiles/main4.dir/main4.cpp.o"

# External object files for target main4
main4_EXTERNAL_OBJECTS =

main4: CMakeFiles/main4.dir/main4.cpp.o
main4: CMakeFiles/main4.dir/build.make
main4: CMakeFiles/main4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_14/lec_14.2/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable main4"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/main4.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/main4.dir/build: main4

.PHONY : CMakeFiles/main4.dir/build

CMakeFiles/main4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/main4.dir/cmake_clean.cmake
.PHONY : CMakeFiles/main4.dir/clean

CMakeFiles/main4.dir/depend:
	cd /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_14/lec_14.2/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_14/lec_14.2 /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_14/lec_14.2 /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_14/lec_14.2/build /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_14/lec_14.2/build /home/keti/cpp_ws/TBCpp/cpp-examples/hong_lab/chapter_14/lec_14.2/build/CMakeFiles/main4.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/main4.dir/depend


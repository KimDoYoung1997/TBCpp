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
CMAKE_SOURCE_DIR = /home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.4/build

# Include any dependencies generated for this target.
include CMakeFiles/Storage.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Storage.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Storage.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Storage.dir/flags.make

CMakeFiles/Storage.dir/Storage.cpp.o: CMakeFiles/Storage.dir/flags.make
CMakeFiles/Storage.dir/Storage.cpp.o: ../Storage.cpp
CMakeFiles/Storage.dir/Storage.cpp.o: CMakeFiles/Storage.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Storage.dir/Storage.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Storage.dir/Storage.cpp.o -MF CMakeFiles/Storage.dir/Storage.cpp.o.d -o CMakeFiles/Storage.dir/Storage.cpp.o -c /home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.4/Storage.cpp

CMakeFiles/Storage.dir/Storage.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Storage.dir/Storage.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.4/Storage.cpp > CMakeFiles/Storage.dir/Storage.cpp.i

CMakeFiles/Storage.dir/Storage.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Storage.dir/Storage.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.4/Storage.cpp -o CMakeFiles/Storage.dir/Storage.cpp.s

# Object files for target Storage
Storage_OBJECTS = \
"CMakeFiles/Storage.dir/Storage.cpp.o"

# External object files for target Storage
Storage_EXTERNAL_OBJECTS =

libStorage.a: CMakeFiles/Storage.dir/Storage.cpp.o
libStorage.a: CMakeFiles/Storage.dir/build.make
libStorage.a: CMakeFiles/Storage.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.4/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libStorage.a"
	$(CMAKE_COMMAND) -P CMakeFiles/Storage.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Storage.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Storage.dir/build: libStorage.a
.PHONY : CMakeFiles/Storage.dir/build

CMakeFiles/Storage.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Storage.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Storage.dir/clean

CMakeFiles/Storage.dir/depend:
	cd /home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.4/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.4 /home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.4 /home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.4/build /home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.4/build /home/keti/TBCpp/cpp-examples/hong_lab/chapter_13/lec_13.4/build/CMakeFiles/Storage.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Storage.dir/depend


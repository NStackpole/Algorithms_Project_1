# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nathan/Algorithms/Project1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nathan/Algorithms/Project1/build

# Include any dependencies generated for this target.
include CMakeFiles/binary-integer-test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/binary-integer-test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/binary-integer-test.dir/flags.make

CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o: CMakeFiles/binary-integer-test.dir/flags.make
CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o: ../BinaryInteger.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nathan/Algorithms/Project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o -c /home/nathan/Algorithms/Project1/BinaryInteger.cpp

CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nathan/Algorithms/Project1/BinaryInteger.cpp > CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.i

CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nathan/Algorithms/Project1/BinaryInteger.cpp -o CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.s

CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o.requires:

.PHONY : CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o.requires

CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o.provides: CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o.requires
	$(MAKE) -f CMakeFiles/binary-integer-test.dir/build.make CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o.provides.build
.PHONY : CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o.provides

CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o.provides.build: CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o


CMakeFiles/binary-integer-test.dir/main.cpp.o: CMakeFiles/binary-integer-test.dir/flags.make
CMakeFiles/binary-integer-test.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nathan/Algorithms/Project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/binary-integer-test.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/binary-integer-test.dir/main.cpp.o -c /home/nathan/Algorithms/Project1/main.cpp

CMakeFiles/binary-integer-test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/binary-integer-test.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nathan/Algorithms/Project1/main.cpp > CMakeFiles/binary-integer-test.dir/main.cpp.i

CMakeFiles/binary-integer-test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/binary-integer-test.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nathan/Algorithms/Project1/main.cpp -o CMakeFiles/binary-integer-test.dir/main.cpp.s

CMakeFiles/binary-integer-test.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/binary-integer-test.dir/main.cpp.o.requires

CMakeFiles/binary-integer-test.dir/main.cpp.o.provides: CMakeFiles/binary-integer-test.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/binary-integer-test.dir/build.make CMakeFiles/binary-integer-test.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/binary-integer-test.dir/main.cpp.o.provides

CMakeFiles/binary-integer-test.dir/main.cpp.o.provides.build: CMakeFiles/binary-integer-test.dir/main.cpp.o


# Object files for target binary-integer-test
binary__integer__test_OBJECTS = \
"CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o" \
"CMakeFiles/binary-integer-test.dir/main.cpp.o"

# External object files for target binary-integer-test
binary__integer__test_EXTERNAL_OBJECTS =

binary-integer-test: CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o
binary-integer-test: CMakeFiles/binary-integer-test.dir/main.cpp.o
binary-integer-test: CMakeFiles/binary-integer-test.dir/build.make
binary-integer-test: CMakeFiles/binary-integer-test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nathan/Algorithms/Project1/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable binary-integer-test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/binary-integer-test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/binary-integer-test.dir/build: binary-integer-test

.PHONY : CMakeFiles/binary-integer-test.dir/build

CMakeFiles/binary-integer-test.dir/requires: CMakeFiles/binary-integer-test.dir/BinaryInteger.cpp.o.requires
CMakeFiles/binary-integer-test.dir/requires: CMakeFiles/binary-integer-test.dir/main.cpp.o.requires

.PHONY : CMakeFiles/binary-integer-test.dir/requires

CMakeFiles/binary-integer-test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/binary-integer-test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/binary-integer-test.dir/clean

CMakeFiles/binary-integer-test.dir/depend:
	cd /home/nathan/Algorithms/Project1/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nathan/Algorithms/Project1 /home/nathan/Algorithms/Project1 /home/nathan/Algorithms/Project1/build /home/nathan/Algorithms/Project1/build /home/nathan/Algorithms/Project1/build/CMakeFiles/binary-integer-test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/binary-integer-test.dir/depend


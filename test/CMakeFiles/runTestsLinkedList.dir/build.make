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
CMAKE_SOURCE_DIR = /home/paulovictorfds/Projects/edi/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/paulovictorfds/Projects/edi/test

# Include any dependencies generated for this target.
include CMakeFiles/runTestsLinkedList.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/runTestsLinkedList.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/runTestsLinkedList.dir/flags.make

CMakeFiles/runTestsLinkedList.dir/testLinkedList.cpp.o: CMakeFiles/runTestsLinkedList.dir/flags.make
CMakeFiles/runTestsLinkedList.dir/testLinkedList.cpp.o: testLinkedList.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/paulovictorfds/Projects/edi/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/runTestsLinkedList.dir/testLinkedList.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/runTestsLinkedList.dir/testLinkedList.cpp.o -c /home/paulovictorfds/Projects/edi/test/testLinkedList.cpp

CMakeFiles/runTestsLinkedList.dir/testLinkedList.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/runTestsLinkedList.dir/testLinkedList.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/paulovictorfds/Projects/edi/test/testLinkedList.cpp > CMakeFiles/runTestsLinkedList.dir/testLinkedList.cpp.i

CMakeFiles/runTestsLinkedList.dir/testLinkedList.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/runTestsLinkedList.dir/testLinkedList.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/paulovictorfds/Projects/edi/test/testLinkedList.cpp -o CMakeFiles/runTestsLinkedList.dir/testLinkedList.cpp.s

# Object files for target runTestsLinkedList
runTestsLinkedList_OBJECTS = \
"CMakeFiles/runTestsLinkedList.dir/testLinkedList.cpp.o"

# External object files for target runTestsLinkedList
runTestsLinkedList_EXTERNAL_OBJECTS =

runTestsLinkedList: CMakeFiles/runTestsLinkedList.dir/testLinkedList.cpp.o
runTestsLinkedList: CMakeFiles/runTestsLinkedList.dir/build.make
runTestsLinkedList: /usr/lib/x86_64-linux-gnu/libgtest.a
runTestsLinkedList: CMakeFiles/runTestsLinkedList.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/paulovictorfds/Projects/edi/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable runTestsLinkedList"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/runTestsLinkedList.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/runTestsLinkedList.dir/build: runTestsLinkedList

.PHONY : CMakeFiles/runTestsLinkedList.dir/build

CMakeFiles/runTestsLinkedList.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/runTestsLinkedList.dir/cmake_clean.cmake
.PHONY : CMakeFiles/runTestsLinkedList.dir/clean

CMakeFiles/runTestsLinkedList.dir/depend:
	cd /home/paulovictorfds/Projects/edi/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/paulovictorfds/Projects/edi/test /home/paulovictorfds/Projects/edi/test /home/paulovictorfds/Projects/edi/test /home/paulovictorfds/Projects/edi/test /home/paulovictorfds/Projects/edi/test/CMakeFiles/runTestsLinkedList.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/runTestsLinkedList.dir/depend

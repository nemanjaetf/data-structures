# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/nemanja_tan/Desktop/htdocs/data-structures/single-linked-lists

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/nemanja_tan/Desktop/htdocs/data-structures/single-linked-lists/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/single_linked_lists.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/single_linked_lists.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/single_linked_lists.dir/flags.make

CMakeFiles/single_linked_lists.dir/main.cpp.o: CMakeFiles/single_linked_lists.dir/flags.make
CMakeFiles/single_linked_lists.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/nemanja_tan/Desktop/htdocs/data-structures/single-linked-lists/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/single_linked_lists.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/single_linked_lists.dir/main.cpp.o -c /Users/nemanja_tan/Desktop/htdocs/data-structures/single-linked-lists/main.cpp

CMakeFiles/single_linked_lists.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/single_linked_lists.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/nemanja_tan/Desktop/htdocs/data-structures/single-linked-lists/main.cpp > CMakeFiles/single_linked_lists.dir/main.cpp.i

CMakeFiles/single_linked_lists.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/single_linked_lists.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/nemanja_tan/Desktop/htdocs/data-structures/single-linked-lists/main.cpp -o CMakeFiles/single_linked_lists.dir/main.cpp.s

# Object files for target single_linked_lists
single_linked_lists_OBJECTS = \
"CMakeFiles/single_linked_lists.dir/main.cpp.o"

# External object files for target single_linked_lists
single_linked_lists_EXTERNAL_OBJECTS =

single_linked_lists: CMakeFiles/single_linked_lists.dir/main.cpp.o
single_linked_lists: CMakeFiles/single_linked_lists.dir/build.make
single_linked_lists: CMakeFiles/single_linked_lists.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/nemanja_tan/Desktop/htdocs/data-structures/single-linked-lists/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable single_linked_lists"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/single_linked_lists.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/single_linked_lists.dir/build: single_linked_lists

.PHONY : CMakeFiles/single_linked_lists.dir/build

CMakeFiles/single_linked_lists.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/single_linked_lists.dir/cmake_clean.cmake
.PHONY : CMakeFiles/single_linked_lists.dir/clean

CMakeFiles/single_linked_lists.dir/depend:
	cd /Users/nemanja_tan/Desktop/htdocs/data-structures/single-linked-lists/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/nemanja_tan/Desktop/htdocs/data-structures/single-linked-lists /Users/nemanja_tan/Desktop/htdocs/data-structures/single-linked-lists /Users/nemanja_tan/Desktop/htdocs/data-structures/single-linked-lists/cmake-build-debug /Users/nemanja_tan/Desktop/htdocs/data-structures/single-linked-lists/cmake-build-debug /Users/nemanja_tan/Desktop/htdocs/data-structures/single-linked-lists/cmake-build-debug/CMakeFiles/single_linked_lists.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/single_linked_lists.dir/depend


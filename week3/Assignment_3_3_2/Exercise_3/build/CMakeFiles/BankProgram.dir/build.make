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
CMAKE_SOURCE_DIR = /home/heidi/projects/C_plusplus_summer_course_2023/week3/Assignment_3_3_2/Exercise_3

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/heidi/projects/C_plusplus_summer_course_2023/week3/Assignment_3_3_2/Exercise_3/build

# Include any dependencies generated for this target.
include CMakeFiles/BankProgram.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/BankProgram.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/BankProgram.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/BankProgram.dir/flags.make

CMakeFiles/BankProgram.dir/main.cpp.o: CMakeFiles/BankProgram.dir/flags.make
CMakeFiles/BankProgram.dir/main.cpp.o: ../main.cpp
CMakeFiles/BankProgram.dir/main.cpp.o: CMakeFiles/BankProgram.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/heidi/projects/C_plusplus_summer_course_2023/week3/Assignment_3_3_2/Exercise_3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/BankProgram.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/BankProgram.dir/main.cpp.o -MF CMakeFiles/BankProgram.dir/main.cpp.o.d -o CMakeFiles/BankProgram.dir/main.cpp.o -c /home/heidi/projects/C_plusplus_summer_course_2023/week3/Assignment_3_3_2/Exercise_3/main.cpp

CMakeFiles/BankProgram.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/BankProgram.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/heidi/projects/C_plusplus_summer_course_2023/week3/Assignment_3_3_2/Exercise_3/main.cpp > CMakeFiles/BankProgram.dir/main.cpp.i

CMakeFiles/BankProgram.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/BankProgram.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/heidi/projects/C_plusplus_summer_course_2023/week3/Assignment_3_3_2/Exercise_3/main.cpp -o CMakeFiles/BankProgram.dir/main.cpp.s

# Object files for target BankProgram
BankProgram_OBJECTS = \
"CMakeFiles/BankProgram.dir/main.cpp.o"

# External object files for target BankProgram
BankProgram_EXTERNAL_OBJECTS =

BankProgram: CMakeFiles/BankProgram.dir/main.cpp.o
BankProgram: CMakeFiles/BankProgram.dir/build.make
BankProgram: src/libbanking_functions.a
BankProgram: src/libaccount_functions.a
BankProgram: src/libdatabase.a
BankProgram: CMakeFiles/BankProgram.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/heidi/projects/C_plusplus_summer_course_2023/week3/Assignment_3_3_2/Exercise_3/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable BankProgram"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/BankProgram.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/BankProgram.dir/build: BankProgram
.PHONY : CMakeFiles/BankProgram.dir/build

CMakeFiles/BankProgram.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/BankProgram.dir/cmake_clean.cmake
.PHONY : CMakeFiles/BankProgram.dir/clean

CMakeFiles/BankProgram.dir/depend:
	cd /home/heidi/projects/C_plusplus_summer_course_2023/week3/Assignment_3_3_2/Exercise_3/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/heidi/projects/C_plusplus_summer_course_2023/week3/Assignment_3_3_2/Exercise_3 /home/heidi/projects/C_plusplus_summer_course_2023/week3/Assignment_3_3_2/Exercise_3 /home/heidi/projects/C_plusplus_summer_course_2023/week3/Assignment_3_3_2/Exercise_3/build /home/heidi/projects/C_plusplus_summer_course_2023/week3/Assignment_3_3_2/Exercise_3/build /home/heidi/projects/C_plusplus_summer_course_2023/week3/Assignment_3_3_2/Exercise_3/build/CMakeFiles/BankProgram.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/BankProgram.dir/depend


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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
CMAKE_SOURCE_DIR = /home/u340545/Pulpit/c++/biblioteki_zew

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/u340545/Pulpit/c++/biblioteki_zew

# Include any dependencies generated for this target.
include CMakeFiles/przyklad_pkg_config.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/przyklad_pkg_config.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/przyklad_pkg_config.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/przyklad_pkg_config.dir/flags.make

CMakeFiles/przyklad_pkg_config.dir/main.cpp.o: CMakeFiles/przyklad_pkg_config.dir/flags.make
CMakeFiles/przyklad_pkg_config.dir/main.cpp.o: main.cpp
CMakeFiles/przyklad_pkg_config.dir/main.cpp.o: CMakeFiles/przyklad_pkg_config.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/home/u340545/Pulpit/c++/biblioteki_zew/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/przyklad_pkg_config.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/przyklad_pkg_config.dir/main.cpp.o -MF CMakeFiles/przyklad_pkg_config.dir/main.cpp.o.d -o CMakeFiles/przyklad_pkg_config.dir/main.cpp.o -c /home/u340545/Pulpit/c++/biblioteki_zew/main.cpp

CMakeFiles/przyklad_pkg_config.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/przyklad_pkg_config.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/u340545/Pulpit/c++/biblioteki_zew/main.cpp > CMakeFiles/przyklad_pkg_config.dir/main.cpp.i

CMakeFiles/przyklad_pkg_config.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/przyklad_pkg_config.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/u340545/Pulpit/c++/biblioteki_zew/main.cpp -o CMakeFiles/przyklad_pkg_config.dir/main.cpp.s

# Object files for target przyklad_pkg_config
przyklad_pkg_config_OBJECTS = \
"CMakeFiles/przyklad_pkg_config.dir/main.cpp.o"

# External object files for target przyklad_pkg_config
przyklad_pkg_config_EXTERNAL_OBJECTS =

przyklad_pkg_config: CMakeFiles/przyklad_pkg_config.dir/main.cpp.o
przyklad_pkg_config: CMakeFiles/przyklad_pkg_config.dir/build.make
przyklad_pkg_config: CMakeFiles/przyklad_pkg_config.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/home/u340545/Pulpit/c++/biblioteki_zew/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable przyklad_pkg_config"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/przyklad_pkg_config.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/przyklad_pkg_config.dir/build: przyklad_pkg_config
.PHONY : CMakeFiles/przyklad_pkg_config.dir/build

CMakeFiles/przyklad_pkg_config.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/przyklad_pkg_config.dir/cmake_clean.cmake
.PHONY : CMakeFiles/przyklad_pkg_config.dir/clean

CMakeFiles/przyklad_pkg_config.dir/depend:
	cd /home/u340545/Pulpit/c++/biblioteki_zew && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/u340545/Pulpit/c++/biblioteki_zew /home/u340545/Pulpit/c++/biblioteki_zew /home/u340545/Pulpit/c++/biblioteki_zew /home/u340545/Pulpit/c++/biblioteki_zew /home/u340545/Pulpit/c++/biblioteki_zew/CMakeFiles/przyklad_pkg_config.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/przyklad_pkg_config.dir/depend


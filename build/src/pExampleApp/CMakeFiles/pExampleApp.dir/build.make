# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /opt/local/bin/cmake

# The command to remove a file.
RM = /opt/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The program to use to edit the cache.
CMAKE_EDIT_COMMAND = /opt/local/bin/ccmake

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/oviquezr/moos-ivp/moos-ivp-extend

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/oviquezr/moos-ivp/moos-ivp-extend/build

# Include any dependencies generated for this target.
include src/pExampleApp/CMakeFiles/pExampleApp.dir/depend.make

# Include the progress variables for this target.
include src/pExampleApp/CMakeFiles/pExampleApp.dir/progress.make

# Include the compile flags for this target's objects.
include src/pExampleApp/CMakeFiles/pExampleApp.dir/flags.make

src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.o: src/pExampleApp/CMakeFiles/pExampleApp.dir/flags.make
src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.o: ../src/pExampleApp/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/oviquezr/moos-ivp/moos-ivp-extend/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.o"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/pExampleApp && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pExampleApp.dir/main.cpp.o -c /Users/oviquezr/moos-ivp/moos-ivp-extend/src/pExampleApp/main.cpp

src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pExampleApp.dir/main.cpp.i"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/pExampleApp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/oviquezr/moos-ivp/moos-ivp-extend/src/pExampleApp/main.cpp > CMakeFiles/pExampleApp.dir/main.cpp.i

src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pExampleApp.dir/main.cpp.s"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/pExampleApp && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/oviquezr/moos-ivp/moos-ivp-extend/src/pExampleApp/main.cpp -o CMakeFiles/pExampleApp.dir/main.cpp.s

src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.o.requires:
.PHONY : src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.o.requires

src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.o.provides: src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.o.requires
	$(MAKE) -f src/pExampleApp/CMakeFiles/pExampleApp.dir/build.make src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.o.provides.build
.PHONY : src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.o.provides

src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.o.provides.build: src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.o

# Object files for target pExampleApp
pExampleApp_OBJECTS = \
"CMakeFiles/pExampleApp.dir/main.cpp.o"

# External object files for target pExampleApp
pExampleApp_EXTERNAL_OBJECTS =

../bin/pExampleApp: src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.o
../bin/pExampleApp: src/pExampleApp/CMakeFiles/pExampleApp.dir/build.make
../bin/pExampleApp: /Users/oviquezr/moos-ivp/MOOS/MOOSCore/lib/libMOOS.a
../bin/pExampleApp: src/pExampleApp/CMakeFiles/pExampleApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../bin/pExampleApp"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/pExampleApp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pExampleApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/pExampleApp/CMakeFiles/pExampleApp.dir/build: ../bin/pExampleApp
.PHONY : src/pExampleApp/CMakeFiles/pExampleApp.dir/build

src/pExampleApp/CMakeFiles/pExampleApp.dir/requires: src/pExampleApp/CMakeFiles/pExampleApp.dir/main.cpp.o.requires
.PHONY : src/pExampleApp/CMakeFiles/pExampleApp.dir/requires

src/pExampleApp/CMakeFiles/pExampleApp.dir/clean:
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/pExampleApp && $(CMAKE_COMMAND) -P CMakeFiles/pExampleApp.dir/cmake_clean.cmake
.PHONY : src/pExampleApp/CMakeFiles/pExampleApp.dir/clean

src/pExampleApp/CMakeFiles/pExampleApp.dir/depend:
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/oviquezr/moos-ivp/moos-ivp-extend /Users/oviquezr/moos-ivp/moos-ivp-extend/src/pExampleApp /Users/oviquezr/moos-ivp/moos-ivp-extend/build /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/pExampleApp /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/pExampleApp/CMakeFiles/pExampleApp.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/pExampleApp/CMakeFiles/pExampleApp.dir/depend


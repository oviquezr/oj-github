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
CMAKE_BINARY_DIR = /Users/oviquezr/moos-ivp/moos-ivp-extend/src

# Include any dependencies generated for this target.
include src/pOdometry/CMakeFiles/pOdometry.dir/depend.make

# Include the progress variables for this target.
include src/pOdometry/CMakeFiles/pOdometry.dir/progress.make

# Include the compile flags for this target's objects.
include src/pOdometry/CMakeFiles/pOdometry.dir/flags.make

src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.o: src/pOdometry/CMakeFiles/pOdometry.dir/flags.make
src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.o: pOdometry/Odometry.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/oviquezr/moos-ivp/moos-ivp-extend/src/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.o"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/src/src/pOdometry && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pOdometry.dir/Odometry.cpp.o -c /Users/oviquezr/moos-ivp/moos-ivp-extend/src/pOdometry/Odometry.cpp

src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pOdometry.dir/Odometry.cpp.i"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/src/src/pOdometry && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/oviquezr/moos-ivp/moos-ivp-extend/src/pOdometry/Odometry.cpp > CMakeFiles/pOdometry.dir/Odometry.cpp.i

src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pOdometry.dir/Odometry.cpp.s"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/src/src/pOdometry && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/oviquezr/moos-ivp/moos-ivp-extend/src/pOdometry/Odometry.cpp -o CMakeFiles/pOdometry.dir/Odometry.cpp.s

src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.o.requires:
.PHONY : src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.o.requires

src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.o.provides: src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.o.requires
	$(MAKE) -f src/pOdometry/CMakeFiles/pOdometry.dir/build.make src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.o.provides.build
.PHONY : src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.o.provides

src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.o.provides.build: src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.o

src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o: src/pOdometry/CMakeFiles/pOdometry.dir/flags.make
src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o: pOdometry/Odometry_Info.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/oviquezr/moos-ivp/moos-ivp-extend/src/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/src/src/pOdometry && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o -c /Users/oviquezr/moos-ivp/moos-ivp-extend/src/pOdometry/Odometry_Info.cpp

src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pOdometry.dir/Odometry_Info.cpp.i"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/src/src/pOdometry && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/oviquezr/moos-ivp/moos-ivp-extend/src/pOdometry/Odometry_Info.cpp > CMakeFiles/pOdometry.dir/Odometry_Info.cpp.i

src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pOdometry.dir/Odometry_Info.cpp.s"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/src/src/pOdometry && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/oviquezr/moos-ivp/moos-ivp-extend/src/pOdometry/Odometry_Info.cpp -o CMakeFiles/pOdometry.dir/Odometry_Info.cpp.s

src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o.requires:
.PHONY : src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o.requires

src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o.provides: src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o.requires
	$(MAKE) -f src/pOdometry/CMakeFiles/pOdometry.dir/build.make src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o.provides.build
.PHONY : src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o.provides

src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o.provides.build: src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o

src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.o: src/pOdometry/CMakeFiles/pOdometry.dir/flags.make
src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.o: pOdometry/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/oviquezr/moos-ivp/moos-ivp-extend/src/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.o"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/src/src/pOdometry && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/pOdometry.dir/main.cpp.o -c /Users/oviquezr/moos-ivp/moos-ivp-extend/src/pOdometry/main.cpp

src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/pOdometry.dir/main.cpp.i"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/src/src/pOdometry && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/oviquezr/moos-ivp/moos-ivp-extend/src/pOdometry/main.cpp > CMakeFiles/pOdometry.dir/main.cpp.i

src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/pOdometry.dir/main.cpp.s"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/src/src/pOdometry && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/oviquezr/moos-ivp/moos-ivp-extend/src/pOdometry/main.cpp -o CMakeFiles/pOdometry.dir/main.cpp.s

src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.o.requires:
.PHONY : src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.o.requires

src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.o.provides: src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.o.requires
	$(MAKE) -f src/pOdometry/CMakeFiles/pOdometry.dir/build.make src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.o.provides.build
.PHONY : src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.o.provides

src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.o.provides.build: src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.o

# Object files for target pOdometry
pOdometry_OBJECTS = \
"CMakeFiles/pOdometry.dir/Odometry.cpp.o" \
"CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o" \
"CMakeFiles/pOdometry.dir/main.cpp.o"

# External object files for target pOdometry
pOdometry_EXTERNAL_OBJECTS =

../bin/pOdometry: src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.o
../bin/pOdometry: src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o
../bin/pOdometry: src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.o
../bin/pOdometry: src/pOdometry/CMakeFiles/pOdometry.dir/build.make
../bin/pOdometry: /Users/oviquezr/moos-ivp/MOOS/MOOSCore/lib/libMOOS.a
../bin/pOdometry: src/pOdometry/CMakeFiles/pOdometry.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../bin/pOdometry"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/src/src/pOdometry && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/pOdometry.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/pOdometry/CMakeFiles/pOdometry.dir/build: ../bin/pOdometry
.PHONY : src/pOdometry/CMakeFiles/pOdometry.dir/build

src/pOdometry/CMakeFiles/pOdometry.dir/requires: src/pOdometry/CMakeFiles/pOdometry.dir/Odometry.cpp.o.requires
src/pOdometry/CMakeFiles/pOdometry.dir/requires: src/pOdometry/CMakeFiles/pOdometry.dir/Odometry_Info.cpp.o.requires
src/pOdometry/CMakeFiles/pOdometry.dir/requires: src/pOdometry/CMakeFiles/pOdometry.dir/main.cpp.o.requires
.PHONY : src/pOdometry/CMakeFiles/pOdometry.dir/requires

src/pOdometry/CMakeFiles/pOdometry.dir/clean:
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/src/src/pOdometry && $(CMAKE_COMMAND) -P CMakeFiles/pOdometry.dir/cmake_clean.cmake
.PHONY : src/pOdometry/CMakeFiles/pOdometry.dir/clean

src/pOdometry/CMakeFiles/pOdometry.dir/depend:
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/src && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/oviquezr/moos-ivp/moos-ivp-extend /Users/oviquezr/moos-ivp/moos-ivp-extend/src/pOdometry /Users/oviquezr/moos-ivp/moos-ivp-extend/src /Users/oviquezr/moos-ivp/moos-ivp-extend/src/src/pOdometry /Users/oviquezr/moos-ivp/moos-ivp-extend/src/src/pOdometry/CMakeFiles/pOdometry.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/pOdometry/CMakeFiles/pOdometry.dir/depend

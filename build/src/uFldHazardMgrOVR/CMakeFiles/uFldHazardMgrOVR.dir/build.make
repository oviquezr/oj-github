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
include src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/depend.make

# Include the progress variables for this target.
include src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/progress.make

# Include the compile flags for this target's objects.
include src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/flags.make

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/flags.make
src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o: ../src/uFldHazardMgrOVR/HazardMgr.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/oviquezr/moos-ivp/moos-ivp-extend/build/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/uFldHazardMgrOVR && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o -c /Users/oviquezr/moos-ivp/moos-ivp-extend/src/uFldHazardMgrOVR/HazardMgr.cpp

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.i"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/uFldHazardMgrOVR && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/oviquezr/moos-ivp/moos-ivp-extend/src/uFldHazardMgrOVR/HazardMgr.cpp > CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.i

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.s"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/uFldHazardMgrOVR && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/oviquezr/moos-ivp/moos-ivp-extend/src/uFldHazardMgrOVR/HazardMgr.cpp -o CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.s

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o.requires:
.PHONY : src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o.requires

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o.provides: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o.requires
	$(MAKE) -f src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/build.make src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o.provides.build
.PHONY : src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o.provides

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o.provides.build: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/flags.make
src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o: ../src/uFldHazardMgrOVR/HazardMgr_Info.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/oviquezr/moos-ivp/moos-ivp-extend/build/CMakeFiles $(CMAKE_PROGRESS_2)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/uFldHazardMgrOVR && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o -c /Users/oviquezr/moos-ivp/moos-ivp-extend/src/uFldHazardMgrOVR/HazardMgr_Info.cpp

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.i"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/uFldHazardMgrOVR && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/oviquezr/moos-ivp/moos-ivp-extend/src/uFldHazardMgrOVR/HazardMgr_Info.cpp > CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.i

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.s"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/uFldHazardMgrOVR && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/oviquezr/moos-ivp/moos-ivp-extend/src/uFldHazardMgrOVR/HazardMgr_Info.cpp -o CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.s

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o.requires:
.PHONY : src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o.requires

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o.provides: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o.requires
	$(MAKE) -f src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/build.make src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o.provides.build
.PHONY : src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o.provides

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o.provides.build: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/flags.make
src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o: ../src/uFldHazardMgrOVR/main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /Users/oviquezr/moos-ivp/moos-ivp-extend/build/CMakeFiles $(CMAKE_PROGRESS_3)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/uFldHazardMgrOVR && /usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o -c /Users/oviquezr/moos-ivp/moos-ivp-extend/src/uFldHazardMgrOVR/main.cpp

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.i"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/uFldHazardMgrOVR && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /Users/oviquezr/moos-ivp/moos-ivp-extend/src/uFldHazardMgrOVR/main.cpp > CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.i

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.s"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/uFldHazardMgrOVR && /usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /Users/oviquezr/moos-ivp/moos-ivp-extend/src/uFldHazardMgrOVR/main.cpp -o CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.s

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o.requires:
.PHONY : src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o.requires

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o.provides: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o.requires
	$(MAKE) -f src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/build.make src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o.provides.build
.PHONY : src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o.provides

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o.provides.build: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o

# Object files for target uFldHazardMgrOVR
uFldHazardMgrOVR_OBJECTS = \
"CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o" \
"CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o" \
"CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o"

# External object files for target uFldHazardMgrOVR
uFldHazardMgrOVR_EXTERNAL_OBJECTS =

../bin/uFldHazardMgrOVR: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o
../bin/uFldHazardMgrOVR: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o
../bin/uFldHazardMgrOVR: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o
../bin/uFldHazardMgrOVR: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/build.make
../bin/uFldHazardMgrOVR: /Users/oviquezr/moos-ivp/MOOS/MOOSCore/lib/libMOOS.a
../bin/uFldHazardMgrOVR: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable ../../../bin/uFldHazardMgrOVR"
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/uFldHazardMgrOVR && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/uFldHazardMgrOVR.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/build: ../bin/uFldHazardMgrOVR
.PHONY : src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/build

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/requires: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr.cpp.o.requires
src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/requires: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/HazardMgr_Info.cpp.o.requires
src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/requires: src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/main.cpp.o.requires
.PHONY : src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/requires

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/clean:
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/uFldHazardMgrOVR && $(CMAKE_COMMAND) -P CMakeFiles/uFldHazardMgrOVR.dir/cmake_clean.cmake
.PHONY : src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/clean

src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/depend:
	cd /Users/oviquezr/moos-ivp/moos-ivp-extend/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/oviquezr/moos-ivp/moos-ivp-extend /Users/oviquezr/moos-ivp/moos-ivp-extend/src/uFldHazardMgrOVR /Users/oviquezr/moos-ivp/moos-ivp-extend/build /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/uFldHazardMgrOVR /Users/oviquezr/moos-ivp/moos-ivp-extend/build/src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/uFldHazardMgrOVR/CMakeFiles/uFldHazardMgrOVR.dir/depend


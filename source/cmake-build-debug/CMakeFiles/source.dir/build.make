# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.15

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Program\C++\PAT\source

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Program\C++\PAT\source\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/source.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/source.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/source.dir/flags.make

CMakeFiles/source.dir/A1001.cpp.obj: CMakeFiles/source.dir/flags.make
CMakeFiles/source.dir/A1001.cpp.obj: ../A1001.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Program\C++\PAT\source\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/source.dir/A1001.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\source.dir\A1001.cpp.obj -c D:\Program\C++\PAT\source\A1001.cpp

CMakeFiles/source.dir/A1001.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/source.dir/A1001.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Program\C++\PAT\source\A1001.cpp > CMakeFiles\source.dir\A1001.cpp.i

CMakeFiles/source.dir/A1001.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/source.dir/A1001.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Program\C++\PAT\source\A1001.cpp -o CMakeFiles\source.dir\A1001.cpp.s

CMakeFiles/source.dir/A1002.cpp.obj: CMakeFiles/source.dir/flags.make
CMakeFiles/source.dir/A1002.cpp.obj: ../A1002.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Program\C++\PAT\source\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/source.dir/A1002.cpp.obj"
	C:\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\source.dir\A1002.cpp.obj -c D:\Program\C++\PAT\source\A1002.cpp

CMakeFiles/source.dir/A1002.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/source.dir/A1002.cpp.i"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Program\C++\PAT\source\A1002.cpp > CMakeFiles\source.dir\A1002.cpp.i

CMakeFiles/source.dir/A1002.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/source.dir/A1002.cpp.s"
	C:\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Program\C++\PAT\source\A1002.cpp -o CMakeFiles\source.dir\A1002.cpp.s

# Object files for target source
source_OBJECTS = \
"CMakeFiles/source.dir/A1001.cpp.obj" \
"CMakeFiles/source.dir/A1002.cpp.obj"

# External object files for target source
source_EXTERNAL_OBJECTS =

source.exe: CMakeFiles/source.dir/A1001.cpp.obj
source.exe: CMakeFiles/source.dir/A1002.cpp.obj
source.exe: CMakeFiles/source.dir/build.make
source.exe: CMakeFiles/source.dir/linklibs.rsp
source.exe: CMakeFiles/source.dir/objects1.rsp
source.exe: CMakeFiles/source.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Program\C++\PAT\source\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable source.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\source.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/source.dir/build: source.exe

.PHONY : CMakeFiles/source.dir/build

CMakeFiles/source.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\source.dir\cmake_clean.cmake
.PHONY : CMakeFiles/source.dir/clean

CMakeFiles/source.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Program\C++\PAT\source D:\Program\C++\PAT\source D:\Program\C++\PAT\source\cmake-build-debug D:\Program\C++\PAT\source\cmake-build-debug D:\Program\C++\PAT\source\cmake-build-debug\CMakeFiles\source.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/source.dir/depend


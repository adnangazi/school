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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2019.3.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2019.3.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "D:\GitHub\University\Programmazione 1\SequenzaCrescente"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\GitHub\University\Programmazione 1\SequenzaCrescente\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/SequenzaCrescente.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SequenzaCrescente.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SequenzaCrescente.dir/flags.make

CMakeFiles/SequenzaCrescente.dir/main.cpp.obj: CMakeFiles/SequenzaCrescente.dir/flags.make
CMakeFiles/SequenzaCrescente.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\GitHub\University\Programmazione 1\SequenzaCrescente\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SequenzaCrescente.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SequenzaCrescente.dir\main.cpp.obj -c "D:\GitHub\University\Programmazione 1\SequenzaCrescente\main.cpp"

CMakeFiles/SequenzaCrescente.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SequenzaCrescente.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\GitHub\University\Programmazione 1\SequenzaCrescente\main.cpp" > CMakeFiles\SequenzaCrescente.dir\main.cpp.i

CMakeFiles/SequenzaCrescente.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SequenzaCrescente.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\GitHub\University\Programmazione 1\SequenzaCrescente\main.cpp" -o CMakeFiles\SequenzaCrescente.dir\main.cpp.s

# Object files for target SequenzaCrescente
SequenzaCrescente_OBJECTS = \
"CMakeFiles/SequenzaCrescente.dir/main.cpp.obj"

# External object files for target SequenzaCrescente
SequenzaCrescente_EXTERNAL_OBJECTS =

SequenzaCrescente.exe: CMakeFiles/SequenzaCrescente.dir/main.cpp.obj
SequenzaCrescente.exe: CMakeFiles/SequenzaCrescente.dir/build.make
SequenzaCrescente.exe: CMakeFiles/SequenzaCrescente.dir/linklibs.rsp
SequenzaCrescente.exe: CMakeFiles/SequenzaCrescente.dir/objects1.rsp
SequenzaCrescente.exe: CMakeFiles/SequenzaCrescente.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\GitHub\University\Programmazione 1\SequenzaCrescente\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SequenzaCrescente.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SequenzaCrescente.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SequenzaCrescente.dir/build: SequenzaCrescente.exe

.PHONY : CMakeFiles/SequenzaCrescente.dir/build

CMakeFiles/SequenzaCrescente.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SequenzaCrescente.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SequenzaCrescente.dir/clean

CMakeFiles/SequenzaCrescente.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\GitHub\University\Programmazione 1\SequenzaCrescente" "D:\GitHub\University\Programmazione 1\SequenzaCrescente" "D:\GitHub\University\Programmazione 1\SequenzaCrescente\cmake-build-debug" "D:\GitHub\University\Programmazione 1\SequenzaCrescente\cmake-build-debug" "D:\GitHub\University\Programmazione 1\SequenzaCrescente\cmake-build-debug\CMakeFiles\SequenzaCrescente.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/SequenzaCrescente.dir/depend

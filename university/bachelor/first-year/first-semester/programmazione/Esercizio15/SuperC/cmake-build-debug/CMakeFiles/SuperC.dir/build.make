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
CMAKE_SOURCE_DIR = "D:\GitHub\University\Programmazione 1\SuperC"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "D:\GitHub\University\Programmazione 1\SuperC\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/SuperC.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SuperC.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SuperC.dir/flags.make

CMakeFiles/SuperC.dir/main.cpp.obj: CMakeFiles/SuperC.dir/flags.make
CMakeFiles/SuperC.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="D:\GitHub\University\Programmazione 1\SuperC\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/SuperC.dir/main.cpp.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\SuperC.dir\main.cpp.obj -c "D:\GitHub\University\Programmazione 1\SuperC\main.cpp"

CMakeFiles/SuperC.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SuperC.dir/main.cpp.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "D:\GitHub\University\Programmazione 1\SuperC\main.cpp" > CMakeFiles\SuperC.dir\main.cpp.i

CMakeFiles/SuperC.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SuperC.dir/main.cpp.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\G__~1.EXE $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "D:\GitHub\University\Programmazione 1\SuperC\main.cpp" -o CMakeFiles\SuperC.dir\main.cpp.s

# Object files for target SuperC
SuperC_OBJECTS = \
"CMakeFiles/SuperC.dir/main.cpp.obj"

# External object files for target SuperC
SuperC_EXTERNAL_OBJECTS =

SuperC.exe: CMakeFiles/SuperC.dir/main.cpp.obj
SuperC.exe: CMakeFiles/SuperC.dir/build.make
SuperC.exe: CMakeFiles/SuperC.dir/linklibs.rsp
SuperC.exe: CMakeFiles/SuperC.dir/objects1.rsp
SuperC.exe: CMakeFiles/SuperC.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="D:\GitHub\University\Programmazione 1\SuperC\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable SuperC.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\SuperC.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SuperC.dir/build: SuperC.exe

.PHONY : CMakeFiles/SuperC.dir/build

CMakeFiles/SuperC.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\SuperC.dir\cmake_clean.cmake
.PHONY : CMakeFiles/SuperC.dir/clean

CMakeFiles/SuperC.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "D:\GitHub\University\Programmazione 1\SuperC" "D:\GitHub\University\Programmazione 1\SuperC" "D:\GitHub\University\Programmazione 1\SuperC\cmake-build-debug" "D:\GitHub\University\Programmazione 1\SuperC\cmake-build-debug" "D:\GitHub\University\Programmazione 1\SuperC\cmake-build-debug\CMakeFiles\SuperC.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/SuperC.dir/depend

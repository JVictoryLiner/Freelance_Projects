# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "E:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "E:\Program Files\JetBrains\CLion 2021.2.3\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\Programming\machprob

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\Programming\machprob\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/machprob.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/machprob.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/machprob.dir/flags.make

CMakeFiles/machprob.dir/main.cpp.obj: CMakeFiles/machprob.dir/flags.make
CMakeFiles/machprob.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programming\machprob\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/machprob.dir/main.cpp.obj"
	"E:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\machprob.dir\main.cpp.obj -c D:\Programming\machprob\main.cpp

CMakeFiles/machprob.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/machprob.dir/main.cpp.i"
	"E:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programming\machprob\main.cpp > CMakeFiles\machprob.dir\main.cpp.i

CMakeFiles/machprob.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/machprob.dir/main.cpp.s"
	"E:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programming\machprob\main.cpp -o CMakeFiles\machprob.dir\main.cpp.s

CMakeFiles/machprob.dir/implementation.cpp.obj: CMakeFiles/machprob.dir/flags.make
CMakeFiles/machprob.dir/implementation.cpp.obj: ../implementation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programming\machprob\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/machprob.dir/implementation.cpp.obj"
	"E:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\machprob.dir\implementation.cpp.obj -c D:\Programming\machprob\implementation.cpp

CMakeFiles/machprob.dir/implementation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/machprob.dir/implementation.cpp.i"
	"E:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programming\machprob\implementation.cpp > CMakeFiles\machprob.dir\implementation.cpp.i

CMakeFiles/machprob.dir/implementation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/machprob.dir/implementation.cpp.s"
	"E:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programming\machprob\implementation.cpp -o CMakeFiles\machprob.dir\implementation.cpp.s

CMakeFiles/machprob.dir/string.cpp.obj: CMakeFiles/machprob.dir/flags.make
CMakeFiles/machprob.dir/string.cpp.obj: ../string.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\Programming\machprob\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/machprob.dir/string.cpp.obj"
	"E:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\machprob.dir\string.cpp.obj -c D:\Programming\machprob\string.cpp

CMakeFiles/machprob.dir/string.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/machprob.dir/string.cpp.i"
	"E:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\Programming\machprob\string.cpp > CMakeFiles\machprob.dir\string.cpp.i

CMakeFiles/machprob.dir/string.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/machprob.dir/string.cpp.s"
	"E:\Program Files\MinGW\mingw64\bin\g++.exe" $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\Programming\machprob\string.cpp -o CMakeFiles\machprob.dir\string.cpp.s

# Object files for target machprob
machprob_OBJECTS = \
"CMakeFiles/machprob.dir/main.cpp.obj" \
"CMakeFiles/machprob.dir/implementation.cpp.obj" \
"CMakeFiles/machprob.dir/string.cpp.obj"

# External object files for target machprob
machprob_EXTERNAL_OBJECTS =

machprob.exe: CMakeFiles/machprob.dir/main.cpp.obj
machprob.exe: CMakeFiles/machprob.dir/implementation.cpp.obj
machprob.exe: CMakeFiles/machprob.dir/string.cpp.obj
machprob.exe: CMakeFiles/machprob.dir/build.make
machprob.exe: CMakeFiles/machprob.dir/linklibs.rsp
machprob.exe: CMakeFiles/machprob.dir/objects1.rsp
machprob.exe: CMakeFiles/machprob.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\Programming\machprob\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Linking CXX executable machprob.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\machprob.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/machprob.dir/build: machprob.exe
.PHONY : CMakeFiles/machprob.dir/build

CMakeFiles/machprob.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\machprob.dir\cmake_clean.cmake
.PHONY : CMakeFiles/machprob.dir/clean

CMakeFiles/machprob.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\Programming\machprob D:\Programming\machprob D:\Programming\machprob\cmake-build-debug D:\Programming\machprob\cmake-build-debug D:\Programming\machprob\cmake-build-debug\CMakeFiles\machprob.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/machprob.dir/depend

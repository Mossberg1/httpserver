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
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/aarch64/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/mossberg/Code/Http

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/mossberg/Code/Http/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Http.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Http.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Http.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Http.dir/flags.make

CMakeFiles/Http.dir/main.c.o: CMakeFiles/Http.dir/flags.make
CMakeFiles/Http.dir/main.c.o: /Users/mossberg/Code/Http/main.c
CMakeFiles/Http.dir/main.c.o: CMakeFiles/Http.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mossberg/Code/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/Http.dir/main.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Http.dir/main.c.o -MF CMakeFiles/Http.dir/main.c.o.d -o CMakeFiles/Http.dir/main.c.o -c /Users/mossberg/Code/Http/main.c

CMakeFiles/Http.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Http.dir/main.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mossberg/Code/Http/main.c > CMakeFiles/Http.dir/main.c.i

CMakeFiles/Http.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Http.dir/main.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mossberg/Code/Http/main.c -o CMakeFiles/Http.dir/main.c.s

CMakeFiles/Http.dir/http/response.c.o: CMakeFiles/Http.dir/flags.make
CMakeFiles/Http.dir/http/response.c.o: /Users/mossberg/Code/Http/http/response.c
CMakeFiles/Http.dir/http/response.c.o: CMakeFiles/Http.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mossberg/Code/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/Http.dir/http/response.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Http.dir/http/response.c.o -MF CMakeFiles/Http.dir/http/response.c.o.d -o CMakeFiles/Http.dir/http/response.c.o -c /Users/mossberg/Code/Http/http/response.c

CMakeFiles/Http.dir/http/response.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Http.dir/http/response.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mossberg/Code/Http/http/response.c > CMakeFiles/Http.dir/http/response.c.i

CMakeFiles/Http.dir/http/response.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Http.dir/http/response.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mossberg/Code/Http/http/response.c -o CMakeFiles/Http.dir/http/response.c.s

CMakeFiles/Http.dir/http/request.c.o: CMakeFiles/Http.dir/flags.make
CMakeFiles/Http.dir/http/request.c.o: /Users/mossberg/Code/Http/http/request.c
CMakeFiles/Http.dir/http/request.c.o: CMakeFiles/Http.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mossberg/Code/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/Http.dir/http/request.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Http.dir/http/request.c.o -MF CMakeFiles/Http.dir/http/request.c.o.d -o CMakeFiles/Http.dir/http/request.c.o -c /Users/mossberg/Code/Http/http/request.c

CMakeFiles/Http.dir/http/request.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Http.dir/http/request.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mossberg/Code/Http/http/request.c > CMakeFiles/Http.dir/http/request.c.i

CMakeFiles/Http.dir/http/request.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Http.dir/http/request.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mossberg/Code/Http/http/request.c -o CMakeFiles/Http.dir/http/request.c.s

CMakeFiles/Http.dir/http/status.c.o: CMakeFiles/Http.dir/flags.make
CMakeFiles/Http.dir/http/status.c.o: /Users/mossberg/Code/Http/http/status.c
CMakeFiles/Http.dir/http/status.c.o: CMakeFiles/Http.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mossberg/Code/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/Http.dir/http/status.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Http.dir/http/status.c.o -MF CMakeFiles/Http.dir/http/status.c.o.d -o CMakeFiles/Http.dir/http/status.c.o -c /Users/mossberg/Code/Http/http/status.c

CMakeFiles/Http.dir/http/status.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Http.dir/http/status.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mossberg/Code/Http/http/status.c > CMakeFiles/Http.dir/http/status.c.i

CMakeFiles/Http.dir/http/status.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Http.dir/http/status.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mossberg/Code/Http/http/status.c -o CMakeFiles/Http.dir/http/status.c.s

CMakeFiles/Http.dir/http/content.c.o: CMakeFiles/Http.dir/flags.make
CMakeFiles/Http.dir/http/content.c.o: /Users/mossberg/Code/Http/http/content.c
CMakeFiles/Http.dir/http/content.c.o: CMakeFiles/Http.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mossberg/Code/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/Http.dir/http/content.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Http.dir/http/content.c.o -MF CMakeFiles/Http.dir/http/content.c.o.d -o CMakeFiles/Http.dir/http/content.c.o -c /Users/mossberg/Code/Http/http/content.c

CMakeFiles/Http.dir/http/content.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Http.dir/http/content.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mossberg/Code/Http/http/content.c > CMakeFiles/Http.dir/http/content.c.i

CMakeFiles/Http.dir/http/content.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Http.dir/http/content.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mossberg/Code/Http/http/content.c -o CMakeFiles/Http.dir/http/content.c.s

CMakeFiles/Http.dir/log/ascii.c.o: CMakeFiles/Http.dir/flags.make
CMakeFiles/Http.dir/log/ascii.c.o: /Users/mossberg/Code/Http/log/ascii.c
CMakeFiles/Http.dir/log/ascii.c.o: CMakeFiles/Http.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mossberg/Code/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building C object CMakeFiles/Http.dir/log/ascii.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Http.dir/log/ascii.c.o -MF CMakeFiles/Http.dir/log/ascii.c.o.d -o CMakeFiles/Http.dir/log/ascii.c.o -c /Users/mossberg/Code/Http/log/ascii.c

CMakeFiles/Http.dir/log/ascii.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Http.dir/log/ascii.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mossberg/Code/Http/log/ascii.c > CMakeFiles/Http.dir/log/ascii.c.i

CMakeFiles/Http.dir/log/ascii.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Http.dir/log/ascii.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mossberg/Code/Http/log/ascii.c -o CMakeFiles/Http.dir/log/ascii.c.s

CMakeFiles/Http.dir/log/stdout.c.o: CMakeFiles/Http.dir/flags.make
CMakeFiles/Http.dir/log/stdout.c.o: /Users/mossberg/Code/Http/log/stdout.c
CMakeFiles/Http.dir/log/stdout.c.o: CMakeFiles/Http.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/mossberg/Code/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building C object CMakeFiles/Http.dir/log/stdout.c.o"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -MD -MT CMakeFiles/Http.dir/log/stdout.c.o -MF CMakeFiles/Http.dir/log/stdout.c.o.d -o CMakeFiles/Http.dir/log/stdout.c.o -c /Users/mossberg/Code/Http/log/stdout.c

CMakeFiles/Http.dir/log/stdout.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing C source to CMakeFiles/Http.dir/log/stdout.c.i"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /Users/mossberg/Code/Http/log/stdout.c > CMakeFiles/Http.dir/log/stdout.c.i

CMakeFiles/Http.dir/log/stdout.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling C source to assembly CMakeFiles/Http.dir/log/stdout.c.s"
	/Library/Developer/CommandLineTools/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /Users/mossberg/Code/Http/log/stdout.c -o CMakeFiles/Http.dir/log/stdout.c.s

# Object files for target Http
Http_OBJECTS = \
"CMakeFiles/Http.dir/main.c.o" \
"CMakeFiles/Http.dir/http/response.c.o" \
"CMakeFiles/Http.dir/http/request.c.o" \
"CMakeFiles/Http.dir/http/status.c.o" \
"CMakeFiles/Http.dir/http/content.c.o" \
"CMakeFiles/Http.dir/log/ascii.c.o" \
"CMakeFiles/Http.dir/log/stdout.c.o"

# External object files for target Http
Http_EXTERNAL_OBJECTS =

Http: CMakeFiles/Http.dir/main.c.o
Http: CMakeFiles/Http.dir/http/response.c.o
Http: CMakeFiles/Http.dir/http/request.c.o
Http: CMakeFiles/Http.dir/http/status.c.o
Http: CMakeFiles/Http.dir/http/content.c.o
Http: CMakeFiles/Http.dir/log/ascii.c.o
Http: CMakeFiles/Http.dir/log/stdout.c.o
Http: CMakeFiles/Http.dir/build.make
Http: CMakeFiles/Http.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/mossberg/Code/Http/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking C executable Http"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Http.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Http.dir/build: Http
.PHONY : CMakeFiles/Http.dir/build

CMakeFiles/Http.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Http.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Http.dir/clean

CMakeFiles/Http.dir/depend:
	cd /Users/mossberg/Code/Http/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/mossberg/Code/Http /Users/mossberg/Code/Http /Users/mossberg/Code/Http/cmake-build-debug /Users/mossberg/Code/Http/cmake-build-debug /Users/mossberg/Code/Http/cmake-build-debug/CMakeFiles/Http.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/Http.dir/depend

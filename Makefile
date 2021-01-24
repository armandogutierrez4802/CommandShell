# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_COMMAND = /usr/bin/cmake3

# The command to remove a file.
RM = /usr/bin/cmake3 -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/csmajs/aguti037/assignment-cs_100_aa_assignment_1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/csmajs/aguti037/assignment-cs_100_aa_assignment_1

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target install/strip
install/strip: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake3 -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip

# Special rule for the target install/strip
install/strip/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing the project stripped..."
	/usr/bin/cmake3 -DCMAKE_INSTALL_DO_STRIP=1 -P cmake_install.cmake
.PHONY : install/strip/fast

# Special rule for the target install/local
install/local: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake3 -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local

# Special rule for the target install/local
install/local/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Installing only the local directory..."
	/usr/bin/cmake3 -DCMAKE_INSTALL_LOCAL_ONLY=1 -P cmake_install.cmake
.PHONY : install/local/fast

# Special rule for the target install
install: preinstall
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake3 -P cmake_install.cmake
.PHONY : install

# Special rule for the target install
install/fast: preinstall/fast
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Install the project..."
	/usr/bin/cmake3 -P cmake_install.cmake
.PHONY : install/fast

# Special rule for the target list_install_components
list_install_components:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Available install components are: \"Unspecified\""
.PHONY : list_install_components

# Special rule for the target list_install_components
list_install_components/fast: list_install_components

.PHONY : list_install_components/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake3 -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/bin/ccmake3 -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /home/csmajs/aguti037/assignment-cs_100_aa_assignment_1/CMakeFiles /home/csmajs/aguti037/assignment-cs_100_aa_assignment_1/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /home/csmajs/aguti037/assignment-cs_100_aa_assignment_1/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named integration

# Build rule for target.
integration: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 integration
.PHONY : integration

# fast build rule for target.
integration/fast:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/build
.PHONY : integration/fast

#=============================================================================
# Target rules for targets named test

# Build rule for target.
test: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 test
.PHONY : test

# fast build rule for target.
test/fast:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/build
.PHONY : test/fast

#=============================================================================
# Target rules for targets named rshell

# Build rule for target.
rshell: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 rshell
.PHONY : rshell

# fast build rule for target.
rshell/fast:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/build
.PHONY : rshell/fast

#=============================================================================
# Target rules for targets named gmock_main

# Build rule for target.
gmock_main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gmock_main
.PHONY : gmock_main

# fast build rule for target.
gmock_main/fast:
	$(MAKE) -f googletest/googlemock/CMakeFiles/gmock_main.dir/build.make googletest/googlemock/CMakeFiles/gmock_main.dir/build
.PHONY : gmock_main/fast

#=============================================================================
# Target rules for targets named gmock

# Build rule for target.
gmock: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gmock
.PHONY : gmock

# fast build rule for target.
gmock/fast:
	$(MAKE) -f googletest/googlemock/CMakeFiles/gmock.dir/build.make googletest/googlemock/CMakeFiles/gmock.dir/build
.PHONY : gmock/fast

#=============================================================================
# Target rules for targets named gtest_main

# Build rule for target.
gtest_main: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gtest_main
.PHONY : gtest_main

# fast build rule for target.
gtest_main/fast:
	$(MAKE) -f googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/build.make googletest/googlemock/gtest/CMakeFiles/gtest_main.dir/build
.PHONY : gtest_main/fast

#=============================================================================
# Target rules for targets named gtest

# Build rule for target.
gtest: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 gtest
.PHONY : gtest

# fast build rule for target.
gtest/fast:
	$(MAKE) -f googletest/googlemock/gtest/CMakeFiles/gtest.dir/build.make googletest/googlemock/gtest/CMakeFiles/gtest.dir/build
.PHONY : gtest/fast

src/and.o: src/and.cpp.o

.PHONY : src/and.o

# target to build an object file
src/and.cpp.o:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/and.cpp.o
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/and.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/and.cpp.o
.PHONY : src/and.cpp.o

src/and.i: src/and.cpp.i

.PHONY : src/and.i

# target to preprocess a source file
src/and.cpp.i:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/and.cpp.i
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/and.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/and.cpp.i
.PHONY : src/and.cpp.i

src/and.s: src/and.cpp.s

.PHONY : src/and.s

# target to generate assembly for a file
src/and.cpp.s:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/and.cpp.s
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/and.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/and.cpp.s
.PHONY : src/and.cpp.s

src/connectors.o: src/connectors.cpp.o

.PHONY : src/connectors.o

# target to build an object file
src/connectors.cpp.o:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/connectors.cpp.o
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/connectors.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/connectors.cpp.o
.PHONY : src/connectors.cpp.o

src/connectors.i: src/connectors.cpp.i

.PHONY : src/connectors.i

# target to preprocess a source file
src/connectors.cpp.i:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/connectors.cpp.i
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/connectors.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/connectors.cpp.i
.PHONY : src/connectors.cpp.i

src/connectors.s: src/connectors.cpp.s

.PHONY : src/connectors.s

# target to generate assembly for a file
src/connectors.cpp.s:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/connectors.cpp.s
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/connectors.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/connectors.cpp.s
.PHONY : src/connectors.cpp.s

src/doubleOutputRed.o: src/doubleOutputRed.cpp.o

.PHONY : src/doubleOutputRed.o

# target to build an object file
src/doubleOutputRed.cpp.o:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/doubleOutputRed.cpp.o
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/doubleOutputRed.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/doubleOutputRed.cpp.o
.PHONY : src/doubleOutputRed.cpp.o

src/doubleOutputRed.i: src/doubleOutputRed.cpp.i

.PHONY : src/doubleOutputRed.i

# target to preprocess a source file
src/doubleOutputRed.cpp.i:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/doubleOutputRed.cpp.i
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/doubleOutputRed.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/doubleOutputRed.cpp.i
.PHONY : src/doubleOutputRed.cpp.i

src/doubleOutputRed.s: src/doubleOutputRed.cpp.s

.PHONY : src/doubleOutputRed.s

# target to generate assembly for a file
src/doubleOutputRed.cpp.s:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/doubleOutputRed.cpp.s
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/doubleOutputRed.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/doubleOutputRed.cpp.s
.PHONY : src/doubleOutputRed.cpp.s

src/executable.o: src/executable.cpp.o

.PHONY : src/executable.o

# target to build an object file
src/executable.cpp.o:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/executable.cpp.o
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/executable.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/executable.cpp.o
.PHONY : src/executable.cpp.o

src/executable.i: src/executable.cpp.i

.PHONY : src/executable.i

# target to preprocess a source file
src/executable.cpp.i:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/executable.cpp.i
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/executable.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/executable.cpp.i
.PHONY : src/executable.cpp.i

src/executable.s: src/executable.cpp.s

.PHONY : src/executable.s

# target to generate assembly for a file
src/executable.cpp.s:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/executable.cpp.s
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/executable.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/executable.cpp.s
.PHONY : src/executable.cpp.s

src/input.o: src/input.cpp.o

.PHONY : src/input.o

# target to build an object file
src/input.cpp.o:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/input.cpp.o
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/input.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/input.cpp.o
.PHONY : src/input.cpp.o

src/input.i: src/input.cpp.i

.PHONY : src/input.i

# target to preprocess a source file
src/input.cpp.i:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/input.cpp.i
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/input.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/input.cpp.i
.PHONY : src/input.cpp.i

src/input.s: src/input.cpp.s

.PHONY : src/input.s

# target to generate assembly for a file
src/input.cpp.s:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/input.cpp.s
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/input.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/input.cpp.s
.PHONY : src/input.cpp.s

src/inputRed.o: src/inputRed.cpp.o

.PHONY : src/inputRed.o

# target to build an object file
src/inputRed.cpp.o:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/inputRed.cpp.o
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/inputRed.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/inputRed.cpp.o
.PHONY : src/inputRed.cpp.o

src/inputRed.i: src/inputRed.cpp.i

.PHONY : src/inputRed.i

# target to preprocess a source file
src/inputRed.cpp.i:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/inputRed.cpp.i
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/inputRed.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/inputRed.cpp.i
.PHONY : src/inputRed.cpp.i

src/inputRed.s: src/inputRed.cpp.s

.PHONY : src/inputRed.s

# target to generate assembly for a file
src/inputRed.cpp.s:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/inputRed.cpp.s
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/inputRed.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/inputRed.cpp.s
.PHONY : src/inputRed.cpp.s

src/integration.o: src/integration.cpp.o

.PHONY : src/integration.o

# target to build an object file
src/integration.cpp.o:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/integration.cpp.o
.PHONY : src/integration.cpp.o

src/integration.i: src/integration.cpp.i

.PHONY : src/integration.i

# target to preprocess a source file
src/integration.cpp.i:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/integration.cpp.i
.PHONY : src/integration.cpp.i

src/integration.s: src/integration.cpp.s

.PHONY : src/integration.s

# target to generate assembly for a file
src/integration.cpp.s:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/integration.cpp.s
.PHONY : src/integration.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/or.o: src/or.cpp.o

.PHONY : src/or.o

# target to build an object file
src/or.cpp.o:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/or.cpp.o
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/or.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/or.cpp.o
.PHONY : src/or.cpp.o

src/or.i: src/or.cpp.i

.PHONY : src/or.i

# target to preprocess a source file
src/or.cpp.i:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/or.cpp.i
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/or.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/or.cpp.i
.PHONY : src/or.cpp.i

src/or.s: src/or.cpp.s

.PHONY : src/or.s

# target to generate assembly for a file
src/or.cpp.s:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/or.cpp.s
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/or.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/or.cpp.s
.PHONY : src/or.cpp.s

src/outputRed.o: src/outputRed.cpp.o

.PHONY : src/outputRed.o

# target to build an object file
src/outputRed.cpp.o:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/outputRed.cpp.o
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/outputRed.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/outputRed.cpp.o
.PHONY : src/outputRed.cpp.o

src/outputRed.i: src/outputRed.cpp.i

.PHONY : src/outputRed.i

# target to preprocess a source file
src/outputRed.cpp.i:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/outputRed.cpp.i
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/outputRed.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/outputRed.cpp.i
.PHONY : src/outputRed.cpp.i

src/outputRed.s: src/outputRed.cpp.s

.PHONY : src/outputRed.s

# target to generate assembly for a file
src/outputRed.cpp.s:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/outputRed.cpp.s
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/outputRed.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/outputRed.cpp.s
.PHONY : src/outputRed.cpp.s

src/parenthesis.o: src/parenthesis.cpp.o

.PHONY : src/parenthesis.o

# target to build an object file
src/parenthesis.cpp.o:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/parenthesis.cpp.o
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/parenthesis.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/parenthesis.cpp.o
.PHONY : src/parenthesis.cpp.o

src/parenthesis.i: src/parenthesis.cpp.i

.PHONY : src/parenthesis.i

# target to preprocess a source file
src/parenthesis.cpp.i:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/parenthesis.cpp.i
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/parenthesis.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/parenthesis.cpp.i
.PHONY : src/parenthesis.cpp.i

src/parenthesis.s: src/parenthesis.cpp.s

.PHONY : src/parenthesis.s

# target to generate assembly for a file
src/parenthesis.cpp.s:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/parenthesis.cpp.s
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/parenthesis.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/parenthesis.cpp.s
.PHONY : src/parenthesis.cpp.s

src/pipe.o: src/pipe.cpp.o

.PHONY : src/pipe.o

# target to build an object file
src/pipe.cpp.o:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/pipe.cpp.o
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/pipe.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/pipe.cpp.o
.PHONY : src/pipe.cpp.o

src/pipe.i: src/pipe.cpp.i

.PHONY : src/pipe.i

# target to preprocess a source file
src/pipe.cpp.i:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/pipe.cpp.i
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/pipe.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/pipe.cpp.i
.PHONY : src/pipe.cpp.i

src/pipe.s: src/pipe.cpp.s

.PHONY : src/pipe.s

# target to generate assembly for a file
src/pipe.cpp.s:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/pipe.cpp.s
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/pipe.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/pipe.cpp.s
.PHONY : src/pipe.cpp.s

src/semicolon.o: src/semicolon.cpp.o

.PHONY : src/semicolon.o

# target to build an object file
src/semicolon.cpp.o:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/semicolon.cpp.o
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/semicolon.cpp.o
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/semicolon.cpp.o
.PHONY : src/semicolon.cpp.o

src/semicolon.i: src/semicolon.cpp.i

.PHONY : src/semicolon.i

# target to preprocess a source file
src/semicolon.cpp.i:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/semicolon.cpp.i
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/semicolon.cpp.i
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/semicolon.cpp.i
.PHONY : src/semicolon.cpp.i

src/semicolon.s: src/semicolon.cpp.s

.PHONY : src/semicolon.s

# target to generate assembly for a file
src/semicolon.cpp.s:
	$(MAKE) -f CMakeFiles/integration.dir/build.make CMakeFiles/integration.dir/src/semicolon.cpp.s
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/src/semicolon.cpp.s
	$(MAKE) -f CMakeFiles/rshell.dir/build.make CMakeFiles/rshell.dir/src/semicolon.cpp.s
.PHONY : src/semicolon.cpp.s

unit_tests/test.o: unit_tests/test.cpp.o

.PHONY : unit_tests/test.o

# target to build an object file
unit_tests/test.cpp.o:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/unit_tests/test.cpp.o
.PHONY : unit_tests/test.cpp.o

unit_tests/test.i: unit_tests/test.cpp.i

.PHONY : unit_tests/test.i

# target to preprocess a source file
unit_tests/test.cpp.i:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/unit_tests/test.cpp.i
.PHONY : unit_tests/test.cpp.i

unit_tests/test.s: unit_tests/test.cpp.s

.PHONY : unit_tests/test.s

# target to generate assembly for a file
unit_tests/test.cpp.s:
	$(MAKE) -f CMakeFiles/test.dir/build.make CMakeFiles/test.dir/unit_tests/test.cpp.s
.PHONY : unit_tests/test.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... install/strip"
	@echo "... install/local"
	@echo "... install"
	@echo "... list_install_components"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... integration"
	@echo "... test"
	@echo "... rshell"
	@echo "... gmock_main"
	@echo "... gmock"
	@echo "... gtest_main"
	@echo "... gtest"
	@echo "... src/and.o"
	@echo "... src/and.i"
	@echo "... src/and.s"
	@echo "... src/connectors.o"
	@echo "... src/connectors.i"
	@echo "... src/connectors.s"
	@echo "... src/doubleOutputRed.o"
	@echo "... src/doubleOutputRed.i"
	@echo "... src/doubleOutputRed.s"
	@echo "... src/executable.o"
	@echo "... src/executable.i"
	@echo "... src/executable.s"
	@echo "... src/input.o"
	@echo "... src/input.i"
	@echo "... src/input.s"
	@echo "... src/inputRed.o"
	@echo "... src/inputRed.i"
	@echo "... src/inputRed.s"
	@echo "... src/integration.o"
	@echo "... src/integration.i"
	@echo "... src/integration.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/or.o"
	@echo "... src/or.i"
	@echo "... src/or.s"
	@echo "... src/outputRed.o"
	@echo "... src/outputRed.i"
	@echo "... src/outputRed.s"
	@echo "... src/parenthesis.o"
	@echo "... src/parenthesis.i"
	@echo "... src/parenthesis.s"
	@echo "... src/pipe.o"
	@echo "... src/pipe.i"
	@echo "... src/pipe.s"
	@echo "... src/semicolon.o"
	@echo "... src/semicolon.i"
	@echo "... src/semicolon.s"
	@echo "... unit_tests/test.o"
	@echo "... unit_tests/test.i"
	@echo "... unit_tests/test.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system


# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/wdaughtridge/CLionProjects/Renderer

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Renderer.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Renderer.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Renderer.dir/flags.make

CMakeFiles/Renderer.dir/main.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Renderer.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/main.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/main.cpp

CMakeFiles/Renderer.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/main.cpp > CMakeFiles/Renderer.dir/main.cpp.i

CMakeFiles/Renderer.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/main.cpp -o CMakeFiles/Renderer.dir/main.cpp.s

CMakeFiles/Renderer.dir/src/Window.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/Window.cpp.o: ../src/Window.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Renderer.dir/src/Window.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/Window.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/Window.cpp

CMakeFiles/Renderer.dir/src/Window.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/Window.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/Window.cpp > CMakeFiles/Renderer.dir/src/Window.cpp.i

CMakeFiles/Renderer.dir/src/Window.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/Window.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/Window.cpp -o CMakeFiles/Renderer.dir/src/Window.cpp.s

CMakeFiles/Renderer.dir/src/Instance.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/Instance.cpp.o: ../src/Instance.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Renderer.dir/src/Instance.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/Instance.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/Instance.cpp

CMakeFiles/Renderer.dir/src/Instance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/Instance.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/Instance.cpp > CMakeFiles/Renderer.dir/src/Instance.cpp.i

CMakeFiles/Renderer.dir/src/Instance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/Instance.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/Instance.cpp -o CMakeFiles/Renderer.dir/src/Instance.cpp.s

CMakeFiles/Renderer.dir/src/PhysicalDevice.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/PhysicalDevice.cpp.o: ../src/PhysicalDevice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Renderer.dir/src/PhysicalDevice.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/PhysicalDevice.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/PhysicalDevice.cpp

CMakeFiles/Renderer.dir/src/PhysicalDevice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/PhysicalDevice.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/PhysicalDevice.cpp > CMakeFiles/Renderer.dir/src/PhysicalDevice.cpp.i

CMakeFiles/Renderer.dir/src/PhysicalDevice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/PhysicalDevice.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/PhysicalDevice.cpp -o CMakeFiles/Renderer.dir/src/PhysicalDevice.cpp.s

CMakeFiles/Renderer.dir/src/LogicalDevice.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/LogicalDevice.cpp.o: ../src/LogicalDevice.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Renderer.dir/src/LogicalDevice.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/LogicalDevice.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/LogicalDevice.cpp

CMakeFiles/Renderer.dir/src/LogicalDevice.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/LogicalDevice.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/LogicalDevice.cpp > CMakeFiles/Renderer.dir/src/LogicalDevice.cpp.i

CMakeFiles/Renderer.dir/src/LogicalDevice.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/LogicalDevice.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/LogicalDevice.cpp -o CMakeFiles/Renderer.dir/src/LogicalDevice.cpp.s

CMakeFiles/Renderer.dir/src/Swapchain.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/Swapchain.cpp.o: ../src/Swapchain.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Renderer.dir/src/Swapchain.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/Swapchain.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/Swapchain.cpp

CMakeFiles/Renderer.dir/src/Swapchain.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/Swapchain.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/Swapchain.cpp > CMakeFiles/Renderer.dir/src/Swapchain.cpp.i

CMakeFiles/Renderer.dir/src/Swapchain.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/Swapchain.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/Swapchain.cpp -o CMakeFiles/Renderer.dir/src/Swapchain.cpp.s

CMakeFiles/Renderer.dir/src/Shader.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/Shader.cpp.o: ../src/Shader.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Renderer.dir/src/Shader.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/Shader.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/Shader.cpp

CMakeFiles/Renderer.dir/src/Shader.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/Shader.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/Shader.cpp > CMakeFiles/Renderer.dir/src/Shader.cpp.i

CMakeFiles/Renderer.dir/src/Shader.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/Shader.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/Shader.cpp -o CMakeFiles/Renderer.dir/src/Shader.cpp.s

CMakeFiles/Renderer.dir/src/GraphicsPipeline.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/GraphicsPipeline.cpp.o: ../src/GraphicsPipeline.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Building CXX object CMakeFiles/Renderer.dir/src/GraphicsPipeline.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/GraphicsPipeline.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/GraphicsPipeline.cpp

CMakeFiles/Renderer.dir/src/GraphicsPipeline.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/GraphicsPipeline.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/GraphicsPipeline.cpp > CMakeFiles/Renderer.dir/src/GraphicsPipeline.cpp.i

CMakeFiles/Renderer.dir/src/GraphicsPipeline.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/GraphicsPipeline.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/GraphicsPipeline.cpp -o CMakeFiles/Renderer.dir/src/GraphicsPipeline.cpp.s

CMakeFiles/Renderer.dir/src/Framebuffer.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/Framebuffer.cpp.o: ../src/Framebuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_9) "Building CXX object CMakeFiles/Renderer.dir/src/Framebuffer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/Framebuffer.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/Framebuffer.cpp

CMakeFiles/Renderer.dir/src/Framebuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/Framebuffer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/Framebuffer.cpp > CMakeFiles/Renderer.dir/src/Framebuffer.cpp.i

CMakeFiles/Renderer.dir/src/Framebuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/Framebuffer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/Framebuffer.cpp -o CMakeFiles/Renderer.dir/src/Framebuffer.cpp.s

CMakeFiles/Renderer.dir/src/CommandBuffer.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/CommandBuffer.cpp.o: ../src/CommandBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_10) "Building CXX object CMakeFiles/Renderer.dir/src/CommandBuffer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/CommandBuffer.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/CommandBuffer.cpp

CMakeFiles/Renderer.dir/src/CommandBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/CommandBuffer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/CommandBuffer.cpp > CMakeFiles/Renderer.dir/src/CommandBuffer.cpp.i

CMakeFiles/Renderer.dir/src/CommandBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/CommandBuffer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/CommandBuffer.cpp -o CMakeFiles/Renderer.dir/src/CommandBuffer.cpp.s

CMakeFiles/Renderer.dir/src/Semaphore.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/Semaphore.cpp.o: ../src/Semaphore.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_11) "Building CXX object CMakeFiles/Renderer.dir/src/Semaphore.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/Semaphore.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/Semaphore.cpp

CMakeFiles/Renderer.dir/src/Semaphore.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/Semaphore.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/Semaphore.cpp > CMakeFiles/Renderer.dir/src/Semaphore.cpp.i

CMakeFiles/Renderer.dir/src/Semaphore.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/Semaphore.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/Semaphore.cpp -o CMakeFiles/Renderer.dir/src/Semaphore.cpp.s

CMakeFiles/Renderer.dir/src/Renderer.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/Renderer.cpp.o: ../src/Renderer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_12) "Building CXX object CMakeFiles/Renderer.dir/src/Renderer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/Renderer.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/Renderer.cpp

CMakeFiles/Renderer.dir/src/Renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/Renderer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/Renderer.cpp > CMakeFiles/Renderer.dir/src/Renderer.cpp.i

CMakeFiles/Renderer.dir/src/Renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/Renderer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/Renderer.cpp -o CMakeFiles/Renderer.dir/src/Renderer.cpp.s

CMakeFiles/Renderer.dir/src/VertexBuffer.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/VertexBuffer.cpp.o: ../src/VertexBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_13) "Building CXX object CMakeFiles/Renderer.dir/src/VertexBuffer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/VertexBuffer.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/VertexBuffer.cpp

CMakeFiles/Renderer.dir/src/VertexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/VertexBuffer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/VertexBuffer.cpp > CMakeFiles/Renderer.dir/src/VertexBuffer.cpp.i

CMakeFiles/Renderer.dir/src/VertexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/VertexBuffer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/VertexBuffer.cpp -o CMakeFiles/Renderer.dir/src/VertexBuffer.cpp.s

CMakeFiles/Renderer.dir/src/IndexBuffer.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/IndexBuffer.cpp.o: ../src/IndexBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_14) "Building CXX object CMakeFiles/Renderer.dir/src/IndexBuffer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/IndexBuffer.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/IndexBuffer.cpp

CMakeFiles/Renderer.dir/src/IndexBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/IndexBuffer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/IndexBuffer.cpp > CMakeFiles/Renderer.dir/src/IndexBuffer.cpp.i

CMakeFiles/Renderer.dir/src/IndexBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/IndexBuffer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/IndexBuffer.cpp -o CMakeFiles/Renderer.dir/src/IndexBuffer.cpp.s

CMakeFiles/Renderer.dir/src/UniformBuffer.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/UniformBuffer.cpp.o: ../src/UniformBuffer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_15) "Building CXX object CMakeFiles/Renderer.dir/src/UniformBuffer.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/UniformBuffer.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/UniformBuffer.cpp

CMakeFiles/Renderer.dir/src/UniformBuffer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/UniformBuffer.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/UniformBuffer.cpp > CMakeFiles/Renderer.dir/src/UniformBuffer.cpp.i

CMakeFiles/Renderer.dir/src/UniformBuffer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/UniformBuffer.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/UniformBuffer.cpp -o CMakeFiles/Renderer.dir/src/UniformBuffer.cpp.s

CMakeFiles/Renderer.dir/src/Model.cpp.o: CMakeFiles/Renderer.dir/flags.make
CMakeFiles/Renderer.dir/src/Model.cpp.o: ../src/Model.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_16) "Building CXX object CMakeFiles/Renderer.dir/src/Model.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Renderer.dir/src/Model.cpp.o -c /Users/wdaughtridge/CLionProjects/Renderer/src/Model.cpp

CMakeFiles/Renderer.dir/src/Model.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Renderer.dir/src/Model.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/wdaughtridge/CLionProjects/Renderer/src/Model.cpp > CMakeFiles/Renderer.dir/src/Model.cpp.i

CMakeFiles/Renderer.dir/src/Model.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Renderer.dir/src/Model.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/wdaughtridge/CLionProjects/Renderer/src/Model.cpp -o CMakeFiles/Renderer.dir/src/Model.cpp.s

# Object files for target Renderer
Renderer_OBJECTS = \
"CMakeFiles/Renderer.dir/main.cpp.o" \
"CMakeFiles/Renderer.dir/src/Window.cpp.o" \
"CMakeFiles/Renderer.dir/src/Instance.cpp.o" \
"CMakeFiles/Renderer.dir/src/PhysicalDevice.cpp.o" \
"CMakeFiles/Renderer.dir/src/LogicalDevice.cpp.o" \
"CMakeFiles/Renderer.dir/src/Swapchain.cpp.o" \
"CMakeFiles/Renderer.dir/src/Shader.cpp.o" \
"CMakeFiles/Renderer.dir/src/GraphicsPipeline.cpp.o" \
"CMakeFiles/Renderer.dir/src/Framebuffer.cpp.o" \
"CMakeFiles/Renderer.dir/src/CommandBuffer.cpp.o" \
"CMakeFiles/Renderer.dir/src/Semaphore.cpp.o" \
"CMakeFiles/Renderer.dir/src/Renderer.cpp.o" \
"CMakeFiles/Renderer.dir/src/VertexBuffer.cpp.o" \
"CMakeFiles/Renderer.dir/src/IndexBuffer.cpp.o" \
"CMakeFiles/Renderer.dir/src/UniformBuffer.cpp.o" \
"CMakeFiles/Renderer.dir/src/Model.cpp.o"

# External object files for target Renderer
Renderer_EXTERNAL_OBJECTS =

Renderer: CMakeFiles/Renderer.dir/main.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/Window.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/Instance.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/PhysicalDevice.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/LogicalDevice.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/Swapchain.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/Shader.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/GraphicsPipeline.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/Framebuffer.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/CommandBuffer.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/Semaphore.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/Renderer.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/VertexBuffer.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/IndexBuffer.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/UniformBuffer.cpp.o
Renderer: CMakeFiles/Renderer.dir/src/Model.cpp.o
Renderer: CMakeFiles/Renderer.dir/build.make
Renderer: CMakeFiles/Renderer.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_17) "Linking CXX executable Renderer"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Renderer.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Renderer.dir/build: Renderer

.PHONY : CMakeFiles/Renderer.dir/build

CMakeFiles/Renderer.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Renderer.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Renderer.dir/clean

CMakeFiles/Renderer.dir/depend:
	cd /Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/wdaughtridge/CLionProjects/Renderer /Users/wdaughtridge/CLionProjects/Renderer /Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug /Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug /Users/wdaughtridge/CLionProjects/Renderer/cmake-build-debug/CMakeFiles/Renderer.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Renderer.dir/depend


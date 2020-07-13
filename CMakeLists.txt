cmake_minimum_required(VERSION 3.16)
project(Renderer)

set(CMAKE_CXX_STANDARD 20)

include_directories(include/)

link_directories(lib/vulkan lib/glfw lib/assimp)
link_libraries(libvulkan.1.2.135.dylib libglfw.3.3.dylib libassimp.5.0.0.dylib)

add_executable(Renderer main.cpp src/Includes.h src/Application.h src/Window.h src/Window.cpp src/Instance.h src/Instance.cpp src/PhysicalDevice.h src/PhysicalDevice.cpp src/LogicalDevice.h src/LogicalDevice.cpp src/Swapchain.h src/Swapchain.cpp src/Shader.h src/Shader.cpp src/GraphicsPipeline.h src/GraphicsPipeline.cpp src/Framebuffer.h src/Framebuffer.cpp src/CommandBuffer.h src/CommandBuffer.cpp src/Semaphore.h src/Semaphore.cpp src/Renderer.h src/Renderer.cpp src/VertexBuffer.h src/VertexBuffer.cpp src/IndexBuffer.h src/IndexBuffer.cpp src/UniformBuffer.h src/UniformBuffer.cpp src/Model.cpp src/Model.h)
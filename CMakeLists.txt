cmake_minimum_required(VERSION 3.28)
project(Vulkan_Tutorial C)

set(CMAKE_C_STANDARD 17)

add_executable(Vulkan_Tutorial main.c
        validationlayer/validationlayer.c validationlayer/validationlayer.h
        app/triangle.c app/triangle.h
)

# GLFW
find_package(glfw3 3.3 REQUIRED)
target_link_libraries(Vulkan_Tutorial glfw)

# Vulkan
find_package(Vulkan REQUIRED)
target_link_libraries(Vulkan_Tutorial vulkan)



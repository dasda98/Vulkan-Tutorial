#include "triangle.h"

#include <cstdio>


void HelloTriangleApplication::run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void HelloTriangleApplication::initWindow() {
    glfwInit(); // Initialize GLFW library

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Tell GLFW to not create an OpenGL context (we use Vulkan)
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Disable resized windows

    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", nullptr, nullptr); // Create window
}

void HelloTriangleApplication::initVulkan() {

}

void HelloTriangleApplication::mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void HelloTriangleApplication::cleanup() {
    glfwDestroyWindow(window);

    glfwTerminate();
}

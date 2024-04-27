#include "triangle.h"

#include <GLFW/glfw3.h>


void HelloTriangleApplication::run() {
    initVulkan();
    mainLoop();
    cleanup();
}

void HelloTriangleApplication::initWindow() {
    glfwInit();
    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
}

void HelloTriangleApplication::initVulkan() {

}

void HelloTriangleApplication::mainLoop() {

}

void HelloTriangleApplication::cleanup() {

}

#include "triangle.h"

#include <stdlib.h>
#include <GLFW/glfw3.h>

const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

GLFWwindow* window;
VkInstance instance;

void run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void initWindow() {
    glfwInit(); // Initialize GLFW library

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Tell GLFW to not create an OpenGL context (we use Vulkan)
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Disable resized windows

    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", NULL, NULL); // Create window
}

void createInstance() {
    // Information about applications (OPTIONAL)
    VkApplicationInfo appInfo;
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    // Information about global extensions and validation layer (REQUIRED)
    VkInstanceCreateInfo createInfo;
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    // Information about GLFW
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions;

    glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    createInfo.enabledExtensionCount = glfwExtensionCount;
    createInfo.ppEnabledExtensionNames = glfwExtensions;

    // Information about validation layer
    createInfo.enabledLayerCount = 0;

    // Check if instance was created successfully
    if (vkCreateInstance(&createInfo, NULL, &instance) != VK_SUCCESS) {
        exit(-1);
    }
}

void initVulkan() {
    createInstance();
}

void mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void cleanup() {
    vkDestroyInstance(instance, NULL);

    glfwDestroyWindow(window);

    glfwTerminate();
}

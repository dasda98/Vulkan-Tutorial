#include "triangle.h"
#include "../validationlayer/validationlayer.h"

// GLFW and Vulkan
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

// Standard library
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

// Global variables
const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

const char* validationLayers[] = {
    "VK_LAYER_KHRONOS_validation"
};


#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

GLFWwindow* window;
VkInstance instance;
VkDebugUtilsMessengerEXT debugMessenger;
VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                                      BASE SECTION
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


void run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void initWindow() {
    glfwInit();

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", NULL, NULL);
}

void initVulkan() {
    createInstance();
    setupDebugMessenger(enableValidationLayers, &instance, &debugMessenger);
}

void mainLoop() {
    while (!glfwWindowShouldClose(window)) {
        glfwPollEvents();
    }
}

void cleanup() {
    if (enableValidationLayers) {
        DestroyDebugUtilsMessengerEXT(instance, debugMessenger, NULL);
    }

    vkDestroyInstance(instance, NULL);

    glfwDestroyWindow(window);
    glfwTerminate();
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//                                                      APPLICATION SECTION
//
////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

const char** getRequiredExtensions(uint32_t* extensionsCount) {
    uint32_t glfwExtensionCount = 0;
    const char** glfwExtensions = glfwGetRequiredInstanceExtensions(&glfwExtensionCount);

    if (glfwExtensions == NULL) {
        fprintf(stderr, "failed to retrieve GLFW extensions!\n");
        return NULL;
    }

    *extensionsCount = glfwExtensionCount;
    const char** extensions = malloc((*extensionsCount + 1) * sizeof(char*));

    if (extensions == NULL) {
        fprintf(stderr, "failed to reallocate memory!\n");
        return NULL;
    }

    for (int i=0; i<glfwExtensionCount; i++) {
        extensions[i] = glfwExtensions[i];
    }

    if (enableValidationLayers) {
        extensions[*extensionsCount] = VK_EXT_DEBUG_UTILS_EXTENSION_NAME;
        (*extensionsCount)++;
    }

    return extensions;
}

void createInstance() {
    if (enableValidationLayers && !checkValidationLayerSupport(validationLayers)) {
        fprintf(stderr, "validation layers requested, but not available!\n");
    }

    // Information about application (optional)
    VkApplicationInfo appInfo = {};
    appInfo.sType = VK_STRUCTURE_TYPE_APPLICATION_INFO;
    appInfo.pApplicationName = "Hello Triangle";
    appInfo.applicationVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.pEngineName = "No Engine";
    appInfo.engineVersion = VK_MAKE_VERSION(1, 0, 0);
    appInfo.apiVersion = VK_API_VERSION_1_0;

    VkInstanceCreateInfo createInfo = {};
    createInfo.sType = VK_STRUCTURE_TYPE_INSTANCE_CREATE_INFO;
    createInfo.pApplicationInfo = &appInfo;

    // Extensions
    uint32_t extensionsCount = 0;
    const char** extensions = getRequiredExtensions(&extensionsCount);

    createInfo.enabledExtensionCount = extensionsCount;
    createInfo.ppEnabledExtensionNames = extensions;

    // Validation layer information
    VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo = {};
    if (enableValidationLayers) {
        createInfo.enabledLayerCount = sizeof(validationLayers)/sizeof(validationLayers[0]);
        createInfo.ppEnabledLayerNames = validationLayers;

        populateDebugMessengerCreateInfo(&debugCreateInfo);
        createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*) &debugCreateInfo;
    } else {
        createInfo.enabledLayerCount = 0;
        createInfo.pNext = NULL;
    }

    if (vkCreateInstance(&createInfo, NULL, &instance) != VK_SUCCESS) {
        fprintf(stderr, "failed to create instance!\n");
    }

    // Free memory
    free(extensions);
}
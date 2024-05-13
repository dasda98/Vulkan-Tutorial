#include "app.h"

#include "../window/window.h"

#include "../validationlayer/validation.h"

#include "../device/physical.h"
#include "../device/logical.h"
#include "../device/device.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



VkInstance instance;
VkDebugUtilsMessengerEXT debugMessenger;


void run() {
    initWindow();
    initVulkan();
    mainLoop();
    cleanup();
}

void createInstance() {
    // Check if Validation layers exist
    if (enableValidationLayers && !checkValidationLayerSupport()) {
        fprintf(stderr, "Validation layers requested, but not available!\n");
        exit(-1);
    }

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
    uint32_t extensionCount = 0;
    const char** extensions = getRequiredExtensions(&extensionCount);

    createInfo.enabledExtensionCount = extensionCount;
    createInfo.ppEnabledExtensionNames = extensions;

    createInfo.flags = 0;

    VkDebugUtilsMessengerCreateInfoEXT debugCreateInfo;

    // Information about validation layer
    if (enableValidationLayers) {
        createInfo.enabledLayerCount = vlSize;
        createInfo.ppEnabledLayerNames = validationLayers;

        populateDebugMessengerCreateInfo(&debugCreateInfo);
        createInfo.pNext = (VkDebugUtilsMessengerCreateInfoEXT*) &debugCreateInfo;
    } else {
        createInfo.enabledLayerCount = 0;
        createInfo.pNext = NULL;
    }

    // Check if instance was created successfully
    if (vkCreateInstance(&createInfo, NULL, &instance) != VK_SUCCESS) {
        fprintf(stderr, "Failed to create instance!\n");
        exit(-1);
    }

    // Free alocated memory
    free(extensions);
}

void initVulkan() {
    createInstance();
    setupDebugMessenger();
    pickPhysicalDevice(instance);
    createLogicalDevice();
}

void setupDebugMessenger() {
    if (!enableValidationLayers) {
        return;
    }

    VkDebugUtilsMessengerCreateInfoEXT createInfo;
    populateDebugMessengerCreateInfo(&createInfo);

    if (CreateDebugUtilsMessengerEXT(instance, &createInfo, NULL, &debugMessenger) != VK_SUCCESS) {
        fprintf(stderr, "Failed to set up debug messenger!\n");
        exit(1);
    }
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
    vkDestroyDevice(device, NULL);

    glfwDestroyWindow(window);

    glfwTerminate();
}

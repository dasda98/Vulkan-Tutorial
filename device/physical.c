#include "physical.h"
#include "device.h"

#include <stdio.h>
#include <stdlib.h>


VkPhysicalDevice physicalDevice = VK_NULL_HANDLE;


QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device) {
    QueueFamilyIndices indices = {};
    indices.isComplete = false;

    uint32_t queueFamilyCount = 0;
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, NULL);

    VkQueueFamilyProperties queueFamilies[queueFamilyCount];
    vkGetPhysicalDeviceQueueFamilyProperties(device, &queueFamilyCount, queueFamilies);

    int i = 0;
    for (int j=0; j<queueFamilyCount; j++) {
        if (queueFamilies[i].queueFlags & VK_QUEUE_GRAPHICS_BIT) {
            indices.graphicsFamily = i;
            indices.isComplete = true;
        }

        if (indices.isComplete) {
            break;
        }

        i++;
    }

    return indices;
}

bool isDeviceSuitable(VkPhysicalDevice device) {
    QueueFamilyIndices indices = findQueueFamilies(device);
    bool isComplete = indices.isComplete;
    //free(indices);

    return isComplete;
}

void pickPhysicalDevice(VkInstance instance) {

    uint32_t deviceCount = 0;
    vkEnumeratePhysicalDevices(instance, &deviceCount, NULL);

    if (deviceCount == 0) {
        fprintf(stderr, "failed to find GPUs with Vulkan support!\n");
        exit(-1);
    }

    VkPhysicalDevice device[deviceCount];
    vkEnumeratePhysicalDevices(instance, &deviceCount, device);

    for (int i=0; i<deviceCount; i++) {
        if (isDeviceSuitable(device[i])) {
            physicalDevice = device[i];
            break;
        }
    }

    if (physicalDevice == VK_NULL_HANDLE) {
        fprintf(stderr, "failed to find a suitable GPU!\n");
        exit(-1);
    }
}


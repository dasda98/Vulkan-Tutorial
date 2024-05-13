#ifndef PHYSICAL_H
#define PHYSICAL_H

#include <stdbool.h>
#include <vulkan/vulkan_core.h>


void pickPhysicalDevice(VkInstance instance);
bool isDeviceSuitable(VkPhysicalDevice device);

typedef struct QueueFamilyIndices {
    uint32_t graphicsFamily;
    bool isComplete;
} QueueFamilyIndices;

QueueFamilyIndices findQueueFamilies(VkPhysicalDevice device);


#endif //PHYSICAL_H

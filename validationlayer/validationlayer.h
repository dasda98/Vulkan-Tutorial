#ifndef VALIDATIONLAYER_H
#define VALIDATIONLAYER_H

#include <stdbool.h>
#include <vulkan/vulkan_core.h>


VkResult CreateDebugUtilsMessengerEXT(
    VkInstance instance,
    const VkDebugUtilsMessengerCreateInfoEXT* pCreateInfo,
    const VkAllocationCallbacks* pAllocator,
    VkDebugUtilsMessengerEXT* pDebugMessenger);

void DestroyDebugUtilsMessengerEXT(
    VkInstance instance,
    VkDebugUtilsMessengerEXT debugMessenger,
    const VkAllocationCallbacks* pAllocator);

void populateDebugMessengerCreateInfo(VkDebugUtilsMessengerCreateInfoEXT* createInfo);

// VkInstance pointer (warning)
void setupDebugMessenger(
    bool enableValidationLayers,
    VkInstance* instance,
    VkDebugUtilsMessengerEXT* debugMessenger);

bool checkValidationLayerSupport(const char** validationLayers);

#endif //VALIDATIONLAYER_H

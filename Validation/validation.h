#ifndef VALIDATION_H
#define VALIDATION_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

#include <stdbool.h>

extern const char* validationLayers[];
extern const bool enableValidationLayers;

bool checkValidationLayerSupport();

#endif //VALIDATION_H

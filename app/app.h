#ifndef TRIANGLE_H
#define TRIANGLE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


extern VkInstance instance;
extern VkDebugUtilsMessengerEXT debugMessenger;

void run();
void createInstance();
void initVulkan();
void setupDebugMessenger();
void mainLoop();
void cleanup();

#endif //TRIANGLE_H

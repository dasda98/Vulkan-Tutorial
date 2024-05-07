#ifndef TRIANGLE_H
#define TRIANGLE_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>

extern const uint32_t WIDTH;
extern const uint32_t HEIGHT;

extern GLFWwindow* window;
extern VkInstance instance;
extern VkDebugUtilsMessengerEXT debugMessenger;

void run();
void initWindow();
void createInstance();
void initVulkan();
void setupDebugMessenger();
void mainLoop();
void cleanup();

#endif //TRIANGLE_H

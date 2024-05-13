#ifndef WINDOW_H
#define WINDOW_H

#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


extern const uint32_t WIDTH;
extern const uint32_t HEIGHT;

extern GLFWwindow* window;

void initWindow();

#endif //WINDOW_H

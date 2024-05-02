#ifndef TRIANGLE_H
#define TRIANGLE_H
#define GLFW_INCLUDE_VULKAN
#include <GLFW/glfw3.h>


const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;


class HelloTriangleApplication {
public:
    void run();

private:
    GLFWwindow* window;
    VkInstance instance;

    void initWindow();
    void createInstance();
    void initVulkan();
    void mainLoop();
    void cleanup();
};



#endif //TRIANGLE_H

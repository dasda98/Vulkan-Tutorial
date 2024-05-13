#include "window.h"


const uint32_t WIDTH = 800;
const uint32_t HEIGHT = 600;

GLFWwindow* window;

void initWindow() {
    glfwInit(); // Initialize GLFW library

    glfwWindowHint(GLFW_CLIENT_API, GLFW_NO_API); // Tell GLFW to not create an OpenGL context (we use Vulkan)
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE); // Disable resized windows

    window = glfwCreateWindow(WIDTH, HEIGHT, "Vulkan", NULL, NULL); // Create window
}
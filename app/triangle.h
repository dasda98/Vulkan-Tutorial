#ifndef TRIANGLE_H
#define TRIANGLE_H

#include <stdbool.h>
#include <stdint.h>


void run();
void initVulkan();
void mainLoop();
void cleanup();

void initWindow();
void createInstance();

// Extensions
const char** getRequiredExtensions(uint32_t* extensionsCount);

// Device
void pickPhysicalDevice();

#endif //TRIANGLE_H

#include "validation.h"

#include <string.h>


const char* validationLayers[] = {
    "VK_LAYER_KHRONOS_validation"
};

#ifdef NDEBUG
    const bool enableValidationLayers = false;
#else
    const bool enableValidationLayers = true;
#endif

bool checkValidationLayerSupport() {
    uint32_t layerCount;
    vkEnumerateInstanceLayerProperties(&layerCount, NULL);

    VkLayerProperties availableLayers[layerCount];
    vkEnumerateInstanceLayerProperties(&layerCount, availableLayers);

    size_t validationLayersSize = sizeof(validationLayers)/sizeof(char *);
    size_t availableLayersSize = sizeof(availableLayers)/sizeof(availableLayers[0]);

    int i, j;
    for (i=0; i<validationLayersSize; i++) {
        const char* layerName = validationLayers[i];
        bool layerFound = false;

        for (j=0; j<availableLayersSize; j++) {
            if (strcmp(layerName, availableLayers[j].layerName) == 0) {
                layerFound = true;
                break;
            }
        }
        if (!layerFound) {
            return false;
        }
    }
    return true;
}
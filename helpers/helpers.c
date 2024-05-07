#include "helpers.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void addElement(const char** *arr, uint32_t* size, const char* newElement) {
     const char** tmp = realloc(*arr,(*size + 1) * sizeof(char*));

    if (tmp == NULL) {
        fprintf(stderr, "Failed to increase array size.\n");
        return;
    }

    tmp[*size] = newElement;
    (*size)++;

    *arr = tmp;
}

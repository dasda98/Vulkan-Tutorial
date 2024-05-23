# Vulkan Tutorial Codes in C

This repository is for learning the Vulkan API from 
[Khronos Vulkan® Tutorial](https://docs.vulkan.org/tutorial/latest/00_Introduction.html).

My operating system is Arch Linux and XMonad tiling window manager.

## Information

This is an application to draw a triangle.

Some steps to draw a triangle:
- [ ] Instance and physical device selection
  - [ ] Validation layer 
- [ ] Logical device and queue families
- [ ] Window surface and swap chain
- [ ] Image views and framebuffers
- [ ] Render passes
- [ ] Graphics pipeline
- [ ] Command pools and command buffers
- [ ] Main loop

## Basic Makefile

``` makefile
CC          = gcc
CFLAGS      = -std=c17 -O2 -Wall
LDFLAGS     = -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
OBJFILES    = triangle.o main.o
TARGET      = triangletest

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

.PHONY: test clean

test:
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJFILES)
```
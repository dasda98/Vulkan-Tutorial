# Vulkan Tutorial Codes

This repository is for learning the Vulkan API from 
[Khronos Vulkan® Tutorial](https://docs.vulkan.org/tutorial/latest/00_Introduction.html).

My operating system is Arch Linux and XMonad tiling window manager.

## Basic Makefile

``` makefile
CC			= gcc
CFLAGS 		= -std=c17 -O2 -Wall
LDFLAGS 	= -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
OBJFILES 	= triangle.o main.o
TARGET 		= triangletest

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

.PHONY: test clean

test:
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJFILES)
```
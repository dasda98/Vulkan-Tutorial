CC			= g++
CFLAGS 		= -std=c++17 -O2 -Wall
LDFLAGS 	= -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
OBJFILES 	= triangle.o main.o
TARGET 		= triangletest

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

.PHONY: clean

clean:
	rm -f $(TARGET) $(OBJFILES)
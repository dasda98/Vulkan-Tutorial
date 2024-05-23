CC			= gcc
CFLAGS 		= -std=c17 -O2 -Wall
LDFLAGS 	= -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
OBJFILES 	= ./app/triangle.o \
			  ./validationlayer/validationlayer.o \
			  main.o
TARGET 		= apptest

all: $(TARGET)

$(TARGET): $(OBJFILES)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJFILES) $(LDFLAGS)

.PHONY: test clean

test:
	./$(TARGET)

clean:
	rm -f $(TARGET) $(OBJFILES)
CC			= gcc
CFLAGS 		= -std=c17 -O2 -Wall
LDFLAGS 	= -lglfw -lvulkan -ldl -lpthread -lX11 -lXxf86vm -lXrandr -lXi
OBJFILES 	= ./window/window.o \
			  ./validationlayer/validation.o \
			  ./device/physical.o \
			  ./helpers/helpers.o \
			  ./app/app.o \
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
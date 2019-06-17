CC = g++
CFLAGS = -g -Wall -O3 -pthread -std=c++17 -ffast-math
TARGET = main

all: $(TARGET)

$(TARGET): ./src/$(TARGET).cpp
	mkdir ./bin/
	$(CC) $(CFLAGS) -o ./bin/$(TARGET) ./src/$(TARGET).cpp

clean:
	$(RM) ./bin/$(TARGET)
	$(RM) -rf ./bin

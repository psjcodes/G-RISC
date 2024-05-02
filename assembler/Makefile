CC = g++ -std=c++17
CFLAGS = -g -Wall -Iinclude
TARGET = assemble

all: $(TARGET)
$(TARGET): src/main.cpp 
	$(CC) $(CFLAGS) -o $(TARGET) src/main.cpp

clean:
	rm -f $(TARGET)
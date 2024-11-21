# Variables
CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = matrixmult
OBJ = main.o matmult.o

# Build target
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

# Compile main file
main.o: main.c
	$(CC) $(CFLAGS) -c main.c

# Compile matmult file
matmult.o: matmult.c
	$(CC) $(CFLAGS) -c matmult.c

# Clean up build files
clean:
	rm -f $(OBJ) $(TARGET)

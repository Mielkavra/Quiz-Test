# Define the compiler and compiler flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Name of your final executable program
TARGET = quiz_program

# Source and object files
SRCS = main.c quiz.c
OBJS = $(SRCS:.c=.o)

# Default rule: builds the program
all: $(TARGET)

# Linking the object files together into the final executable
$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $(TARGET)

# Rule for compiling individual .c files when they change
%.o: %.c quiz.h
	$(CC) $(CFLAGS) -c $< -o $@

# Clean rule to delete old build files
clean:
	rm -f $(OBJS) $(TARGET)
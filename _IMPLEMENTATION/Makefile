# Name of the project
PROJECT_NAME = Hamming

# Output directory
BUILD = build

# All source code files
SRC = main.c\
src/hamming1.c

# All test source files
TEST_SRC = src/hamming1.c\
test/test.c

TEST_OUTPUT = $(BUILD)/Test_$(PROJECT_NAME).out

# All include folders with header files
INC	= -Iinc

PROJECT_OUTPUT = $(BUILD)/$(PROJECT_NAME).out

# Document files
DOCUMENTATION_OUTPUT = documentation/html

# Default target built
$(PROJECT_NAME):all

# Run the target even if the matching name exists
.PHONY: run clean test  doc all

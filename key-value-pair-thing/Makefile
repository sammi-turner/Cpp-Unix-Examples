# Compiler to use
CXX = clang++

# Compiler flags
CXXFLAGS = -std=c++20 -Iinclude

# Target executable name
TARGET = main

# Directories
SRC_DIR = src
BIN_DIR = bin
INCLUDE_DIR = include

# Source and object files
SRCS = $(wildcard $(SRC_DIR)/*.cpp)
OBJS = $(patsubst $(SRC_DIR)/%.cpp, $(BIN_DIR)/%.o, $(SRCS))

# Rule for building the target
$(BIN_DIR)/$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) $^ -o $@

# Rule for generating object files
$(BIN_DIR)/%.o: $(SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up
clean:
	rm -f $(BIN_DIR)/*.o $(BIN_DIR)/$(TARGET)
# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++17 -Wall -Wextra -O2

# Directories
SRC_DIR := src
BUILD_DIR := build

# Targets
TARGETS := $(BUILD_DIR)/main $(BUILD_DIR)/main_h

# Source files
MAIN_SRCS := $(SRC_DIR)/main.cc $(SRC_DIR)/noise_power.cc
MAIN_H_SRCS := $(SRC_DIR)/main_h.cc $(SRC_DIR)/noise_power.cc $(SRC_DIR)/noise_helper.cc

# Object files
MAIN_OBJS := $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(MAIN_SRCS))
MAIN_H_OBJS := $(patsubst $(SRC_DIR)/%.cc, $(BUILD_DIR)/%.o, $(MAIN_H_SRCS))

# Default rule
all: $(TARGETS)

# Ensure build directory exists
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# Link rules
$(BUILD_DIR)/main: $(MAIN_OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN_OBJS)

$(BUILD_DIR)/main_h: $(MAIN_H_OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $(MAIN_H_OBJS)

# Compile rule
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cc | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean up build artifacts
clean:
	@rm -fr $(BUILD_DIR)

# Rebuild everything
rebuild: clean all

# Declare phony targets
.PHONY: all clean rebuild
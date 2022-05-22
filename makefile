# Indicate specific C++ compiler
CXX := g++
# Variable used as compiler flags saying to display all warnings (-Wall) and the -c flag indicating compilation without linkage
# Compiling without linkage means that the file will compile without trying to connect its functionality to other files 
CXXFLAGS := -c -Wall

SRC_DIR := ./src
BUILD_DIR := ./obj

# List of all object files compiled into the build directory retaining directory structure of source files
# Find all cpp source files
OBJ_FILES := $(shell find $(SRC_DIR) -name "*.cpp")
# Swap ./src with ./obj for each file path
OBJ_FILES := $(OBJ_FILES:$(SRC_DIR)%=$(BUILD_DIR)%)
# Change list of .cpp extension files to .o extensions
OBJ_FILES := $(OBJ_FILES:%.cpp=%.o)

.PHONY: all setup clean

############################################################
######################## File Lists ########################
############################################################

BASIC_TOPICS_SRC_DIR := $(SRC_DIR)/basic-topics
BASIC_TOPICS_OBJ_DIR := $(BUILD_DIR)/basic-topics

############################################################
################## Makefile Build Targets ##################
############################################################

all: setup reference.out

# Establish build organization and do other pre-compilation actions
setup:
   # Create directory for object files and subdirectories for better organization
	@mkdir -p obj $(BASIC_TOPICS_OBJ_DIR)

# Compile reference program
reference.out: $(OBJ_FILES) main-program.cpp
	$(CXX) main-program.cpp $(OBJ_FILES) -Wall -o $@

$(BUILD_DIR)/functionality-catalog.o: $(SRC_DIR)/functionality-catalog.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Compile basic-topics directory files
$(BASIC_TOPICS_OBJ_DIR)/%.o: $(BASIC_TOPICS_SRC_DIR)/%.cpp
	$(CXX) $(CXXFLAGS) $^ -o $@

# Convenient target for deleting all compilation objects and program
clean:
   # Delete (remove) the reference.out file and compilation object directory
	rm -R reference.out $(BUILD_DIR)/
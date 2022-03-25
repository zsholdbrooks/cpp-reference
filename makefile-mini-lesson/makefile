# Variable to indicate specific C++ compiler
CXX := g++
# Variable used as compiler flags saying to display all warnings (-Wall) and the -c flag indicating compilation without linkage
# Compiling without linkage means that the file will compile without trying to connect its functionality to other files 
CXXFLAGS := -c -Wall

# List of all source files without directory paths
SOURCE_FILES := repeater-interface.cpp repeat-print.cpp sum-square.cpp
# Define build object directory since in larger projects, it may be nested under a larger build directory
BUILD_OBJ_DIR := obj

# Take list of source files and translate to object file located in the object directory
#	Ex: repeater-interface.cpp -> obj/repeater-interface.o
# Must include all objects when linking at main-program. It doesn't recursively nest since symbols are not resolved anywhere.
OBJECT_FILES := $(SOURCE_FILES:%.cpp=$(BUILD_OBJ_DIR)/%.o)

# Explicitly tell make that these following commands are just named commands and do not correspond to files with that name
#   If there is a file such as "hello" in the directory and hello is not listed as a PHONY target, make will not run the
#   hello target and simply report "'hello' is up to date." despite your intent of it being just a command.
.PHONY: all setup clean hello pattern-substitution demonstrate-wildcard

##########################################################################
############################## Make Targets ##############################
##########################################################################

# Since this is the first target in the makefile, running just "make" will execute this target as default.
# Dependencies are in order of setup then main-program so that organization can be done before compilation.
all: setup main-program

# Establish build organization and do other pre-compilation actions
setup:
   # Create directory for object files for better organization
	mkdir -p obj

# Main point of compilation
main-program: repeater-interface.o sum-square.o
   # Compile file containing main() and link object (.o) files together to condense to single executable
	$(CXX) -o example.out main-makefile-program.cpp $(OBJECT_FILES)
   # If we don't care specifically what the list of object files are in obj/, we can use a wildcard
   # for equivalent functionality to above line
   # $(CXX) -o example.out main-makefile-program.cpp $(wildcard $(BUILD_OBJ_DIR)/*.o)
	
repeater-interface.o: repeat-print.o
   # g++ -c -Wall directory-one/repeater-interface.cpp -o obj/repeater-interface.o
	$(CXX) $(CXXFLAGS) directory-one/repeater-interface.cpp -o $(BUILD_OBJ_DIR)/repeater-interface.o

repeat-print.o:
   # g++ -c -Wall directory-one/subdirectory-one/repeat-print.cpp -o obj/repeat-print.o
	$(CXX) $(CXXFLAGS) directory-one/subdirectory-one/repeat-print.cpp -o $(BUILD_OBJ_DIR)/repeat-print.o

sum-square.o:
   # g++ -c -Wall directory-two/sum-square.cpp -o obj/sum-square.o
	$(CXX) $(CXXFLAGS) directory-two/sum-square.cpp -o $(BUILD_OBJ_DIR)/sum-square.o

# Convenient target for deleting all compilation objects and program
clean:
   # Delete (remove) the example.out file and compilation object directory
	rm -R example.out $(BUILD_OBJ_DIR)/


##########################################################################
################# Non-compilation Makefile Functionality #################
##########################################################################

hello:
	echo Hello!

# Make arbitrary text for purposes of demonstrating pattern substitution
MY_TEXT := Just throw a ball

# Pattern substitution is relevant when manipulating batches of files with common names
#	Ex: Object files ending with .o or source files ending with .cpp
#    Note that % is a wildcard character similar to the .* expression used in regexes to indicate
#    any character in any particular quantity
pattern-substitution:
   # subst substitutes raw text for the replacement per space separated word
   # Here all o's are replaced with an e, so "throw" becomes "threw" without affecting other characters
	echo $(subst o,e,$(MY_TEXT))
   # patsubst substitutes a pattern for a replacement pattern per space separated word
   # Here the words ending with "ow" are replaced with the same word ending with "ew"
	echo $(patsubst %ow,%ew,$(MY_TEXT))
   # This syntax is equivalent to the patsubst expression above by keying off a variable
   # $(patsubst pattern,replacement,$(variable)) is equivalent to $(variable:pattern=replacement)
	echo $(MY_TEXT:%ow=%ew)

# Evaluate $(STUFF) for Linux wildcard expansion by the command, not make
CPP_EXTENSION := *.cpp
# Random extension that shouldn't match any files
RANDOM_EXTENSION := *.random

# This demonstrates the difference between wildcard and the wildcard character *
# The issue comes into who does the wildcard expansion (search for matches). If there are no matches found by Linux
# rather than wildcard, then it will interpret the variable directly as a string. This becomes a problem if you use
# the same technique in compilation alongside g++.
demonstrate-wildcard:
   # Note the below command doesn't work 
	echo ${*.cpp}
   # This format works since the echo command does the expansion directly itself
	echo *.cpp
   # This format works but can also be interpreted as a string if cpp files are not found
	echo $(CPP_EXTENSION)
   # This expression will return either a list of cpp files or nothing
	echo $(wildcard $(CPP_EXTENSION))

   # The @ symbol suppresses echo of command being run
	@echo "\n\nProblem with wildcard character:"
   # A string will be unintentionally reported here rather than a list of files
	echo *.random
   # A string will be unintentionally reported here rather than a list of files
	echo $(RANDOM_EXTENSION)
   # Since the make explicitly does the search with the wildcard operator, nothing is echoed here as intended 
	echo $(wildcard $(RANDOM_EXTENSION))
# Variable to indicate specific compiler
CXX := g++
# Variable used as compiler flags saying to display all warnings and the -c flag indicating compilation without linkage
# Compiling without linkage means that the file will compile without trying to connect its functionality elsewhere 
CXX_FLAGS := -c -Wall
# Must include all object when linking at main-program. It doesn't recursively nest since symbols are not resolved anywhere.
OBJECT_FILES := repeater-interface.o repeat-print.o sum-square.o

all: main-program

main-program: repeater-interface.o sum-square.o
	$(CXX) -o example.out main-makefile-program.cpp $(OBJECT_FILES)
	
repeater-interface.o: repeat-print.o
	$(CXX) $(CXX_FLAGS) directory-one/repeater-interface.cpp

repeat-print.o:
	$(CXX) $(CXX_FLAGS) directory-one/subdirectory-one/repeat-print.cpp

sum-square.o:
	$(CXX) $(CXX_FLAGS) directory-two/sum-square.cpp

clean:
	rm -f $(OBJECT_FILES) example.out
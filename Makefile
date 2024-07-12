CXX = g++
CXXFLAGS = -Wall -g -std=c++14

# List of object files
OBJ = main.o ADD.o CHS.o COMBINE.o COPY.o GOTO.o IF.o MyLinkedList.o Receiver.o SET.o VARINT.o VARLIST.o GET.o

# List of header files
DEPS = ADD.h CHS.h COMBINE.h COPY.h GOTO.h IF.h Instruction.h IntegerNode.h ListNode.h MyLinkedList.h Node.h Receiver.h SET.h VARINT.h VARLIST.h DataType.h GET.h

# Default target
all: main

# Rule to create object files
%.o: %.cpp $(DEPS)
	$(CXX) -c -o $@ $< $(CXXFLAGS)

# Rule to link the program
main: $(OBJ)
	$(CXX) -o $@ $^ $(CXXFLAGS)

# Clean up
clean:
	rm -f $(OBJ) main

# Mark 'clean' as a phony target
.PHONY: clean

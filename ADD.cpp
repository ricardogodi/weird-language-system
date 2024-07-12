#include "ADD.h"
#include "Receiver.h"
#include "IntegerNode.h"
#include <stdexcept>
#include <string>

// Constructor for the ADD class. It initializes the base Instruction class with the passed arguments.
ADD::ADD(const vector<string>& args) : Instruction(args) {
    
}

// The execute method for the ADD instruction.
// It performs the addition operation on two integer data types.
void ADD::execute(Receiver& receiver) {
    // Ensures that exactly two arguments are passed to the ADD instruction.
    if (args.size() != 2) {
        throw invalid_argument("ADD requires exactly two arguments");
    }

    const string& arg1 = args[0]; // First argument for addition.
    const string& arg2 = args[1]; // Second argument for addition.

    // Retrieve data from the receiver based on the provided arguments.
    DataType* data1 = receiver.getDataFromMemory(arg1);
    DataType* data2 = receiver.getDataFromMemory(arg2);

    // Checks if the data for both arguments was successfully retrieved.
    if (!data1 || !data2) {
        throw runtime_error("One or more identifiers not found in data memory");
    }

    // Dynamic casting to ensure both data types are IntegerNode.
    IntegerNode* int1 = dynamic_cast<IntegerNode*>(data1);
    IntegerNode* int2 = dynamic_cast<IntegerNode*>(data2);

    // Checks if both data types are indeed integer nodes.
    if (!int1 || !int2) {
        throw runtime_error("One or more identifiers are not integers");
    }

    // Performs the addition operation on the integer values.
    int1->value += int2->value;

    // Updates the data memory in the receiver with the new value.
    receiver.updateDataMemory(arg1, std::unique_ptr<IntegerNode>(new IntegerNode(int1->value)));
}

#include "CHS.h"
#include "Receiver.h"
#include "IntegerNode.h"
#include <stdexcept>
#include <string>

// Constructor for the CHS class. Initializes the base Instruction class with the passed arguments.
CHS::CHS(const vector<string>& args) : Instruction(args) {}

// The execute method for the CHS instruction.
void CHS::execute(Receiver& receiver) {
    // Check that exactly one argument is provided to the CHS instruction.
    if (args.size() != 1) {
        throw invalid_argument("CHS requires exactly one argument");
    }

    // Retrieve the variable name from the arguments.
    const string& var_name = args[0];

    // Retrieve data from the receiver's memory using the variable name.
    DataType* data = receiver.getDataFromMemory(var_name);
    if (!data) {
        // If data is not found, throw an error.
        throw runtime_error("Variable not found: " + var_name);
    }

    // Attempt to cast the data to an IntegerNode.
    IntegerNode* intNode = dynamic_cast<IntegerNode*>(data);
    if (!intNode) {
        // If the cast fails, throw an error indicating the variable is not an integer.
        throw runtime_error("Variable is not an integer: " + var_name);
    }

    // Change the sign of the integer's value.
    intNode->value = -intNode->value;

    // Update the data in the receiver's memory with the new value.
    receiver.updateDataMemory(var_name, std::unique_ptr<IntegerNode>(new IntegerNode(intNode->value)));
}

#include "VARINT.h"
#include "Receiver.h"
#include "IntegerNode.h"
#include <stdexcept>

// Constructor for the VARINT class.
VARINT::VARINT(const vector<string>& args) : Instruction(args) {}

// Execute method for VARINT, creates a new integer variable.
void VARINT::execute(Receiver& receiver) {
    // Ensures that exactly two arguments are passed.
    if (args.size() != 2) {
        throw invalid_argument("VARINT requires exactly two arguments");
    }

    const string& var_name = args[0]; // Name of the new integer variable.
    int value = stoi(args[1]); // Convert string to integer.

    // Create a new IntegerNode and assign the integer value to the variable.
    receiver.updateDataMemory(var_name, std::unique_ptr<IntegerNode>(new IntegerNode(value)));
}

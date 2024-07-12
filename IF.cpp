#include "IF.h"
#include "Receiver.h"
#include "MyLinkedList.h"
#include "IntegerNode.h"
#include <stdexcept>

// Constructor for the IF class, initializes jumpLine to -1 (indicating no jump by default).
IF::IF(const vector<string>& args) : Instruction(args), jumpLine(-1) {}

// Execute method for the IF instruction.
void IF::execute(Receiver& receiver) {
    // Ensures that exactly two arguments are passed (identifier and jump line number).
    if (args.size() != 2) {
        throw invalid_argument("IF requires exactly two arguments");
    }

    const string& x_identifier = args[0]; // The identifier to check.
    jumpLine = stoi(args[1]); // Line number to jump to if condition is met.

    // Retrieve the value associated with the identifier from receiver's memory.
    DataType* x_value = receiver.getDataFromMemory(x_identifier);

    // Check if the identifier exists in memory.
    if (!x_value) {
        throw runtime_error("Identifier not found: " + x_identifier);
    }

    // Check if the value is either an empty list or an integer with value zero.
    MyLinkedList* list = dynamic_cast<MyLinkedList*>(x_value);
    IntegerNode* intNode = dynamic_cast<IntegerNode*>(x_value);
    if ((list && list->is_empty()) || (intNode && intNode->value == 0)) {
        // If condition is met, jumpLine is already set.
    } else {
        jumpLine = -1; // Reset jumpLine to -1 if condition is not met.
    }
}

// Getter method for the jump line number.
int IF::getJumpLine() const {
    return jumpLine;
}

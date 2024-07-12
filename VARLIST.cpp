#include "VARLIST.h"
#include "Receiver.h"
#include "MyLinkedList.h"
#include "IntegerNode.h"
#include <stdexcept>
#include <iostream>
#include <string>

// Constructor for the VARLIST class.
VARLIST::VARLIST(const vector<string>& args) : Instruction(args) {}

// Execute method for VARLIST, creates a new list variable.
void VARLIST::execute(Receiver& receiver) {
    // Ensures that at least one argument is passed.
    if (args.empty()) {
        throw invalid_argument("VARLIST requires at least one argument");
    }

    const string& var_name = args[0]; // Name of the new list variable.
    std::unique_ptr<MyLinkedList> linked_list(new MyLinkedList());


    // Iterating through the arguments to populate the list.
    for (size_t i = 1; i < args.size(); ++i) {
        string valueStr = args[i];

        // Remove trailing comma if present.
        size_t commaPos = valueStr.find(',');
        if (commaPos != string::npos) {
            valueStr = valueStr.substr(0, commaPos);
        }

        int value = stoi(valueStr); // Convert string to integer.
        linked_list->append(std::unique_ptr<IntegerNode>(new IntegerNode(value))); // Append to the list.
    }

    // Update the receiver's data memory with the new list variable.
    receiver.updateDataMemory(var_name, move(linked_list));
}

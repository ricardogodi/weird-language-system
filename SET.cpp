#include "SET.h"
#include "Receiver.h"
#include "MyLinkedList.h"
#include "IntegerNode.h"
#include <stdexcept>
#include <regex>

// Constructor for the SET class.
SET::SET(const vector<string>& args) : Instruction(args) {}

// Execute method for SET, sets a value in a list variable.
void SET::execute(Receiver& receiver) {
    // Ensures that exactly three arguments are passed.
    if (args.size() != 3) {
        throw invalid_argument("SET requires exactly three arguments");
    }

    const string& value_or_identifier = args[0]; // Value or variable name to set.
    int index = stoi(args[1]); // Index at which to set the value in the list.
    const string& list_identifier = args[2]; // List variable name.

    // Retrieving list data from receiver's memory.
    DataType* list_data = receiver.getDataFromMemory(list_identifier);

    // Checks if the list is found.
    if (!list_data) {
        throw runtime_error("List not found: " + list_identifier);
    }

    // Dynamic casting to confirm the data type is MyLinkedList.
    MyLinkedList* list = dynamic_cast<MyLinkedList*>(list_data);

    // Checks if the variable is indeed a list.
    if (!list) {
        throw runtime_error("Identifier is not a list: " + list_identifier);
    }

    // Regex to check if value_or_identifier is an integer constant.
    regex integer_regex("^\\d+$");
    if (regex_match(value_or_identifier, integer_regex)) {
        // Set the integer value at the specified index in the list.
        list->set_at_index(index, std::unique_ptr<IntegerNode>(new IntegerNode(std::stoi(value_or_identifier))));
    } else {
        // Retrieve the variable from receiver's data memory.
        DataType* value_data = receiver.getDataFromMemory(value_or_identifier);

        // Checks if the variable is found.
        if (!value_data) {
            throw runtime_error("Invalid identifier: " + value_or_identifier);
        }

        // Set the value at the specified index in the list.
        list->set_at_index(index, value_data->deep_copy()); // Deep copy for data integrity.
    }
}

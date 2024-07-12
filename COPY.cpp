#include "COPY.h"
#include "Receiver.h"
#include "MyLinkedList.h"
#include <stdexcept>
#include <string>
#include <memory>

// Constructor for COPY class, calls base class constructor with args.
COPY::COPY(const vector<string>& args) : Instruction(args) {}

// Execute method for COPY, performs a shallow copy of a linked list.
void COPY::execute(Receiver& receiver) {
    // Checks for exactly two arguments (source and target list identifiers).
    if (args.size() != 2) {
        throw invalid_argument("COPY requires exactly two arguments");
    }

    const string& target_list_identifier = args[0]; // Target list identifier.
    const string& source_list_identifier = args[1]; // Source list identifier.

    // Retrieving source list from the receiver's data memory.
    DataType* source_data = receiver.getDataFromMemory(source_list_identifier);
    if (!source_data) {
        throw runtime_error("Source list not found: " + source_list_identifier);
    }

    // Dynamic casting to confirm the source data type is MyLinkedList.
    MyLinkedList* source_list = dynamic_cast<MyLinkedList*>(source_data);
    if (!source_list) {
        throw runtime_error("Source identifier is not a list: " + source_list_identifier);
    }

    // Creating a new list for the shallow copy and updating the target identifier in receiver's memory.
    unique_ptr<MyLinkedList> copied_list(new MyLinkedList(*source_list));
    receiver.updateDataMemory(target_list_identifier, move(copied_list));
}

#include "GET.h"
#include "Receiver.h"
#include "MyLinkedList.h"
#include "DataType.h"
#include <stdexcept>

// Constructor for GET class.
GET::GET(const vector<string>& args) : Instruction(args) {
   
}

// Execute method for GET, retrieves an element from a list.
void GET::execute(Receiver& receiver) {
    // Ensures that exactly three arguments are passed.
    if (args.size() != 3) {
        throw invalid_argument("GET requires exactly three arguments");
    }

    const string& var_name = args[0]; // Variable name to store the retrieved data.
    int index = stoi(args[1]); // Index to retrieve data from in the list.
    const string& list_name = args[2]; // Name of the list to retrieve data from.

    // Retrieving list data from receiver's memory.
    DataType* list_data = receiver.getDataFromMemory(list_name);

    // Checks if the list is found.
    if (!list_data) {
        throw runtime_error("List not found: " + list_name);
    }

    // Dynamic casting to confirm the data type is MyLinkedList.
    MyLinkedList* linked_list = dynamic_cast<MyLinkedList*>(list_data);

    // Checks if the variable is indeed a list.
    if (!linked_list) {
        throw runtime_error("Identifier is not a list: " + list_name);
    }

    // Retrieves data at specified index.
    DataType* data_at_index = linked_list->get_at_index(index);

    // Checks if the index is within bounds.
    if (!data_at_index) {
        throw runtime_error("Index out of bounds in list: " + list_name);
    }

    // Updates the receiver's data memory with the retrieved data.
    receiver.updateDataMemory(var_name, unique_ptr<DataType>(data_at_index)); // SHALLOW COPY AS PER PROJECT INSTRUCTIONS
}

#include "COMBINE.h"
#include "Receiver.h"
#include "MyLinkedList.h"
#include <iostream>
#include <stdexcept>

// Constructor for COMBINE class, calls base class constructor with args.
COMBINE::COMBINE(const vector<string>& args) : Instruction(args) {}

// Execute method for COMBINE, combines two linked lists.
void COMBINE::execute(Receiver& receiver) {
    // Checks for exactly two arguments (names of the lists to combine).
    if (args.size() != 2) {
        throw invalid_argument("COMBINE requires exactly two arguments");
    }

    const string& list1Name = args[0]; // First list name.
    const string& list2Name = args[1]; // Second list name.

    // Retrieving lists from the receiver's data memory.
    DataType* data1 = receiver.getDataFromMemory(list1Name);
    DataType* data2 = receiver.getDataFromMemory(list2Name);

    // Checks if both lists are found.
    if (!data1 || !data2) {
        throw runtime_error("One or both lists not found");
    }

    // Dynamic casting to confirm both data types are MyLinkedList.
    MyLinkedList* list1 = dynamic_cast<MyLinkedList*>(data1);
    MyLinkedList* list2 = dynamic_cast<MyLinkedList*>(data2);

    // Checks if both variables are indeed lists.
    if (!list1 || !list2) {
        throw runtime_error("One or both identifiers are not lists");
    }

    // Combining both lists and updating the second list with the combined result.
    MyLinkedList combinedList = list1->concat(*list2);
    receiver.updateDataMemory(list2Name, std::unique_ptr<MyLinkedList>(new MyLinkedList(combinedList)));

}

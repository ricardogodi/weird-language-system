#ifndef NODE_H
#define NODE_H

#include <memory>
#include "DataType.h"

// Node class used in the linked list implementation.
class Node {
public:
    unique_ptr<DataType> value; // Holds the data of the node.
    Node* next_node; // Pointer to the next node in the list.

    // Constructor for Node, takes ownership of the DataType object.
    Node(unique_ptr<DataType> val) : value(move(val)), next_node(nullptr) {}
};

#endif // NODE_H

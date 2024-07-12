#ifndef INTEGER_NODE_H
#define INTEGER_NODE_H

#include <string>
#include "DataType.h"

// Class representing an integer data type in the system.
class IntegerNode : public DataType {
public:
    int value; // Value of the integer.

    // Constructor initializing the integer node with a value.
    IntegerNode(int val) : value(val) {}

    // Overridden method to perform a deep copy of the IntegerNode.
    unique_ptr<DataType> deep_copy() const override {
        return std::unique_ptr<IntegerNode>(new IntegerNode(value));
    }

    // Overridden method to convert the integer value to a string.
    string to_string() const override {
        return std::to_string(value);
    }
};

#endif // INTEGER_NODE_H

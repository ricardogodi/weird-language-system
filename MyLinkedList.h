#ifndef MYLINKEDLIST_H
#define MYLINKEDLIST_H

#include "Node.h"
#include <memory>
#include <sstream>

// MyLinkedList class, derived from DataType, represents a linked list.
class MyLinkedList : public DataType {
private:
    Node* head; // Pointer to the first node of the list.
    Node* tail; // Pointer to the last node of the list.

public:
    MyLinkedList(); // Default constructor.
    MyLinkedList(const MyLinkedList& other); // Copy constructor.
    ~MyLinkedList(); // Destructor.
    MyLinkedList& operator=(const MyLinkedList& other); // Assignment operator.

    void append(unique_ptr<DataType> value); // Append data to the list.
    MyLinkedList concat(const MyLinkedList& other_list) const; // Concatenate two lists.

    bool is_empty() const; // Check if the list is empty.
    DataType* get_at_index(int index) const; // Get data at a specific index.
    void set_at_index(int index, unique_ptr<DataType> value); // Set data at a specific index.

    string to_string() const override; // Convert list to string representation.
    unique_ptr<DataType> deep_copy() const override; // Deep copy of the list.
};

#endif // MYLINKEDLIST_H

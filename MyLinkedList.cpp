#include "MyLinkedList.h"
#include "IntegerNode.h"

// Default constructor - initializes head and tail to nullptr.
MyLinkedList::MyLinkedList() : head(nullptr), tail(nullptr) {
    
}

// Copy constructor - performs a shallow copy of the other list.
MyLinkedList::MyLinkedList(const MyLinkedList& other) : head(nullptr), tail(nullptr) {
    Node* current_node = other.head;
    while (current_node != nullptr) {
        // Clone each node's value and append to this list.
        // Dynamic casting is used to determine the type of data in each node.
        if (IntegerNode* intNode = dynamic_cast<IntegerNode*>(current_node->value.get())) {
            append(std::unique_ptr<IntegerNode>(new IntegerNode(*intNode)));
        } else if (MyLinkedList* listNode = dynamic_cast<MyLinkedList*>(current_node->value.get())) {
            append(std::unique_ptr<MyLinkedList>(new MyLinkedList(*listNode)));
        }
        current_node = current_node->next_node;
    }
}

// Destructor - deallocates all nodes in the list.
MyLinkedList::~MyLinkedList() {
    Node* current = head;
    while (current != nullptr) {
        Node* next = current->next_node;
        delete current;
        current = next;
    }
}

// Append method - adds a new element to the end of the list.
void MyLinkedList::append(unique_ptr<DataType> value) {
    Node* new_node = new Node(move(value));
    if (!head) {
        head = new_node;
        tail = new_node;
    } else {
        tail->next_node = new_node;
        tail = new_node;
    }
}

// Concat method - returns a new list that is the concatenation of this list and another list.
MyLinkedList MyLinkedList::concat(const MyLinkedList& other_list) const {
    MyLinkedList concatenated_list;
    for (Node* current_node = head; current_node != nullptr; current_node = current_node->next_node) {
        // Perform deep copies of the elements and append to the concatenated list.
        concatenated_list.append(current_node->value->deep_copy());
    }
    for (Node* current_node = other_list.head; current_node != nullptr; current_node = current_node->next_node) {
        concatenated_list.append(current_node->value->deep_copy());
    }
    return concatenated_list;
}

// Check if the list is empty - returns true if the list is empty.
bool MyLinkedList::is_empty() const {
    return head == nullptr;
}

// Get value at index - returns the data at a specific index in the list.
DataType* MyLinkedList::get_at_index(int index) const {
    if (index < 0 || is_empty()) {
        throw out_of_range("Index out of bounds");
    }

    Node* current_node = head;
    for (int current_index = 0; current_node != nullptr && current_index < index; ++current_index) {
        current_node = current_node->next_node;
    }

    if (current_node == nullptr) {
        throw out_of_range("Index out of bounds");
    }
    return current_node->value.get();
}

// Set value at index - updates the data at a specific index in the list.
void MyLinkedList::set_at_index(int index, unique_ptr<DataType> value) {
    if (index < 0) {
        throw out_of_range("Index out of bounds");
    }

    Node* current = head;
    for (int idx = 0; current != nullptr && idx < index; ++idx) {
        current = current->next_node;
    }

    if (current == nullptr) {
        throw out_of_range("Index out of bounds");
    }
    current->value = move(value);
}

// Deep copy method - creates a deep copy of the entire list.
unique_ptr<DataType> MyLinkedList::deep_copy() const {
    std::unique_ptr<MyLinkedList> copied_list(new MyLinkedList());
    for (Node* current_node = head; current_node != nullptr; current_node = current_node->next_node) {
        copied_list->append(current_node->value->deep_copy());
    }
    return copied_list;
}

// Convert list to string - provides a string representation of the list.
string MyLinkedList::to_string() const {
    ostringstream oss;
    for (Node* current_node = head; current_node; current_node = current_node->next_node) {
        oss << current_node->value->to_string();
        if (current_node->next_node) {
            oss << ", ";
        }
    }
    return "(" + oss.str() + ")";
}

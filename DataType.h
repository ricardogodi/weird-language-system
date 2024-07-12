#ifndef DATATYPE_H
#define DATATYPE_H

#include <memory>
#include <string>

using namespace std;

// Abstract base class representing a data type.
class DataType {
public:
    // Virtual destructor to allow for proper cleanup in derived classes.
    virtual ~DataType() = default;

    // Pure virtual function to create a deep copy of the object.
    virtual unique_ptr<DataType> deep_copy() const = 0;

    // Virtual function to get a string representation of the data type.
    virtual string to_string() const = 0;
};

#endif // DATATYPE_H

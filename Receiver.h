#ifndef RECEIVER_H
#define RECEIVER_H

#include "DataType.h"
#include <map>
#include <string>
#include <vector>
#include <memory>

// Receiver class handles the execution environment for instructions.
class Receiver {
private:
    map<string, unique_ptr<DataType>> data_memory; // Stores data variables.
    vector<string> program_memory;                 // Stores program instructions.
    int pc;                                        // Program Counter (pc) to track current instruction.

public:
    Receiver();

    // Load initial data into the receiver's memory.
    void loadDataMemory(const map<string, unique_ptr<DataType>>& memory);

    // Load program instructions into memory.
    void loadProgramMemory(const vector<string>& memory);

    // Set the program counter to a specific instruction line.
    void setProgramCounter(int counter);

    // Get the current value of the program counter.
    int getProgramCounter() const;

    // Increment the program counter by one.
    void incrementProgramCounter();

    // Get the next instruction to be executed.
    string getNextInstruction();

    // Get the total number of instructions in the program.
    int getProgramMemorySize() const;

    // Update a specific data variable in memory.
    void updateDataMemory(const string& key, unique_ptr<DataType> value);

    // Retrieve a specific data variable from memory.
    DataType* getDataFromMemory(const string& key);

    // Get a constant reference to the data memory.
    const map<string, unique_ptr<DataType>>& getDataMemory() const;
};

#endif // RECEIVER_H

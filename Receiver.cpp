#include "Receiver.h"

// Constructor initializing the program counter.
Receiver::Receiver() : pc(0) {}

// Load data into the receiver's memory with deep copies.
void Receiver::loadDataMemory(const map<string, unique_ptr<DataType>>& memory) {
    for (const auto& pair : memory) {
        data_memory[pair.first] = pair.second->deep_copy(); // Deep copy to avoid shared ownership issues.
    }
}

// Load program instructions into memory.
void Receiver::loadProgramMemory(const vector<string>& memory) {
    program_memory = memory;
}

// Set the program counter to a specific line.
void Receiver::setProgramCounter(int counter) {
    pc = counter;
}

// Get the current line number from the program counter.
int Receiver::getProgramCounter() const {
    return pc;
}

// Increment the program counter by one.
void Receiver::incrementProgramCounter() {
    pc++;
}

// Retrieve the next instruction to be executed.
string Receiver::getNextInstruction() {
    if (pc < program_memory.size()) {
        return program_memory[pc]; // Returns current instruction and leaves pc unmodified.
    }
    return ""; // Returns empty string if no more instructions.
}

// Get the total number of instructions in the program memory.
int Receiver::getProgramMemorySize() const {
    return program_memory.size();
}

// Update a specific data variable in memory.
void Receiver::updateDataMemory(const string& key, unique_ptr<DataType> value) {
    data_memory[key] = move(value); // Move semantics for efficient memory management.
}

// Retrieve a specific data variable from memory.
DataType* Receiver::getDataFromMemory(const string& key) {
    auto it = data_memory.find(key);
    if (it != data_memory.end()) {
        return it->second.get(); // Returns the raw pointer to the data.
    }
    return nullptr; // Returns nullptr if key not found.
}

// Get a constant reference to the data memory.
const map<string, unique_ptr<DataType>>& Receiver::getDataMemory() const {
    return data_memory;
}

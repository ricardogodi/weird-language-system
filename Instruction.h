#ifndef INSTRUCTION_H
#define INSTRUCTION_H

#include <vector>
#include <string>
#include "Receiver.h"  // Include Receiver for interaction with the execution environment.

// Abstract base class for all instruction types.
class Instruction {
protected:
    vector<string> args; // Arguments for the instruction.

public:
    // Constructor initializing the instruction with arguments.
    Instruction(const vector<string>& args) : args(args) {}

    // Pure virtual function 'execute' to be implemented by derived classes.
    virtual void execute(Receiver& receiver) = 0;

    // Virtual destructor for proper cleanup in derived classes.
    virtual ~Instruction() {};
};

#endif // INSTRUCTION_H

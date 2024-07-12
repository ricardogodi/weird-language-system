#ifndef COPY_H
#define COPY_H

#include "Instruction.h"
#include "Receiver.h"
#include <string>
#include <vector>

// COPY class, derived from Instruction, is used to copy a linked list.
class COPY : public Instruction {
public:
    // Constructor for COPY, initializing with arguments.
    COPY(const vector<string>& args);

    // Overridden execute method to perform the copy operation.
    void execute(Receiver& receiver) override;
};

#endif // COPY_H

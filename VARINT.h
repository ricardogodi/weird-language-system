#ifndef VARINT_H
#define VARINT_H

#include "Instruction.h"
#include <string>
#include <vector>

// VARINT class, derived from Instruction, is used for creating an integer variable.
class VARINT : public Instruction {
public:
    // Constructor for VARINT, initializing with arguments.
    VARINT(const vector<string>& args);

    // Overridden execute method for the VARINT operation.
    void execute(Receiver& receiver) override;
};

#endif // VARINT_H

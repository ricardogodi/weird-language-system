#ifndef IF_H
#define IF_H

#include "Instruction.h"
#include <string>
#include <vector>

// IF class, derived from Instruction, used for conditional jumps in instructions.
class IF : public Instruction {
private:
    int jumpLine; // Line number to jump to if condition is met.

public:
    // Constructor for IF, initializing with arguments.
    IF(const vector<string>& args);

    // Overridden execute method to perform the conditional operation.
    void execute(Receiver& receiver) override;

    // Getter for the jump line number.
    int getJumpLine() const;
};

#endif // IF_H

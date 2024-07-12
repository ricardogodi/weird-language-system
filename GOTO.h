#ifndef GOTO_H
#define GOTO_H

#include "Instruction.h"
#include <string>
#include <vector>

// GOTO class, derived from Instruction, is used for jump operations in instructions.
class GOTO : public Instruction {
private:
    int jumpLine; // Line number to jump to.

public:
    // Constructor for GOTO, initializing with arguments.
    GOTO(const vector<string>& args);

    // Overridden execute method to perform the jump operation.
    void execute(Receiver& receiver) override;

    // Getter for the line number to jump to.
    int getJumpLine() const;
};

#endif // GOTO_H

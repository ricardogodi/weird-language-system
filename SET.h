#ifndef SET_H
#define SET_H

#include "Instruction.h"
#include <string>
#include <vector>

// SET class, derived from Instruction, is used for setting the value in a list variable.
class SET : public Instruction {
public:
    // Constructor for SET, initializing with arguments.
    SET(const vector<string>& args);

    // Overridden execute method for the SET operation.
    void execute(Receiver& receiver) override;
};

#endif // SET_H

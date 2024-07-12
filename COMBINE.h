#ifndef COMBINE_H
#define COMBINE_H

#include "Instruction.h"
#include "Receiver.h"
#include <string>
#include <vector>

// COMBINE class, derived from Instruction, is used to combine two linked lists.
class COMBINE : public Instruction {
public:
    // Constructor for COMBINE, initializing with arguments.
    COMBINE(const vector<string>& args);

    // Overridden execute method to perform the combine operation.
    void execute(Receiver& receiver) override;
};

#endif // COMBINE_H

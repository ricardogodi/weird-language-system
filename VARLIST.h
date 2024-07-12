#ifndef VARLIST_H
#define VARLIST_H

#include "Instruction.h"
#include <string>
#include <vector>

// VARLIST class, derived from Instruction, is used for creating a list variable.
class VARLIST : public Instruction {
public:
    // Constructor for VARLIST, initializing with arguments.
    VARLIST(const vector<string>& args);

    // Overridden execute method for the VARLIST operation.
    void execute(Receiver& receiver) override;
};

#endif // VARLIST_H

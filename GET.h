#ifndef GET_H
#define GET_H

#include "Instruction.h"
#include "Receiver.h"
#include <string>
#include <vector>

// GET class, derived from Instruction, used for retrieving an element from a list.
class GET : public Instruction {
public:
    // Constructor for GET, initializing with arguments.
    GET(const vector<string>& args);

    // Overridden execute method for performing the get operation.
    void execute(Receiver& receiver) override;
};

#endif // GET_H

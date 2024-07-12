#ifndef CHS_H
#define CHS_H

#include "Instruction.h"
#include "Receiver.h"
#include <string>
#include <vector>

// CHS class is derived from the Instruction class and is used to change the sign of an integer.
class CHS : public Instruction {
public:
    // Constructor for CHS, taking a vector of strings as arguments.
    CHS(const vector<string>& args);

    // Overridden execute method from the Instruction class.
    // This method will change the sign of the integer associated with the provided variable name.
    void execute(Receiver& receiver) override;
};

#endif // CHS_H

#ifndef ADD_H
#define ADD_H

#include "Instruction.h"
#include "Receiver.h"
#include <string>
#include <vector>

// The ADD class is derived from the Instruction class and is used to perform addition operations.
class ADD : public Instruction {
public:
    // Constructor that initializes the ADD instruction with arguments.
    ADD(const vector<string>& args);

    // Overridden execute method from the Instruction class.
    // This method will be used to perform the actual addition operation.
    void execute(Receiver& receiver) override;
};

#endif // ADD_H

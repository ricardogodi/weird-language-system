#include "GOTO.h"
#include "Receiver.h"
#include <stdexcept>

// Constructor for GOTO class, initializes jumpLine with -1 (no jump by default).
GOTO::GOTO(const vector<string>& args) : Instruction(args), jumpLine(-1) {}

// Execute method for GOTO, sets the line number to jump to.
void GOTO::execute(Receiver& receiver) {
    // Ensures that exactly one argument is passed.
    if (args.size() != 1) {
        throw invalid_argument("GOTO requires exactly one argument");
    }

    // The argument is the line number to jump to.
    jumpLine = stoi(args[0]);
}

// Getter method to retrieve the jump line number.
int GOTO::getJumpLine() const {
    return jumpLine;
}

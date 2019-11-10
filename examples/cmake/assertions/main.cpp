#include <iostream>
#include <string>
#include <stdexcept>
#include "../../../include/mint/mint.h"

using std::cout;
using std::endl;
using std::string;
using std::domain_error;

void willThrow();
void willNotThrow();

int main() {

    //Declare and intialize Mint
    Mint m;

    //Title test
    m.title("Testing Assertions");

    //Assertions
    m.equal(2, 2, "number equality");
    m.equal(1, 4, "number inequality");
    m.assert(true, "true", "true is not true");
    m.assert(false, "false", "false is false");

    m.throws(willThrow, "throws caught from throwing function", "willThrow() failed to throw");
    m.throws(willNotThrow, "throws not caught from non-throwing function", "willNotThrow() failed to throw");

    //Finish tests, and return exit code
    return m.end();
}

void willThrow() {
    throw domain_error("Error");
}

void willNotThrow() {
    return;
}

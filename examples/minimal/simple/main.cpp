#include "../../../include/mint/mint.h"

int main() {

    //Declare and intialize Mint
    Mint m;

    //Title test
    m.title("Testing Integer Equality");

    //Assertions
    m.equal(10, 10, "integers of same value are equal");

    //Finish tests, and return exit code
    return m.end();
}

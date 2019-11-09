#include <iostream>
#include <string>
#include "include/mint/mint.h"

using std::cout;
using std::endl;
using std::string;

int main() {

    Mint m;
    m.title("Sample Test");
    m.equal(2, 2, "number equality");
    m.equal(1, 4, "number inequality");
    m.assert(true, "true", "true is not true");
    m.assert(false, "false", "false is false");

}

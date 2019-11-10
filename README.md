# Mint
![mint-image](https://i.imgur.com/pRvSub6.png)

Mint is a minimal header-only C++ test runner.

## Installation
A `CMakeLists.txt` file has been added for simple linking with CMake. For more on this, check the [`examples/`](examples) directory.

## Usage
Using Mint is intentionally simple. The basic flow of a test program using Mint:

1. Initialize a Mint object.
2. Call assertions.
3. Return with `end()` to clean-up and return with status code.

Example:

```cpp
#include <iostream>
#include <mint/mint.h>

using std::cout;
using std::endl;

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

```

## Expected output
A snippet from one test:
```
===============
  Sample Test
===============
✔ number equality
✘ number inequality
    FAIL: Expected "4", found: "1"
✔ true
✘ false
    FAIL: false is false
✔ throws caught from throwing function
✘ throws not caught from non-throwing function
    FAIL: willNotThrow() failed to throw (function did not throw)

FAIL! 3 tests failing with 3 tests passing. Returned with exit code "1".
```

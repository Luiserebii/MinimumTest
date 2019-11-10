# Mint
![mint-image](https://i.imgur.com/aM2SNDD.png)

![GitHub](https://img.shields.io/github/license/Luiserebii/Mint?color=g)
[![CircleCI](https://circleci.com/gh/Luiserebii/Mint.svg?style=svg)](https://circleci.com/gh/Luiserebii/Mint)

Mint is a minimal header-only C++ test runner.

## Installation
A `CMakeLists.txt` file has been added for simple linking with CMake. For more on this, check the [`examples/`](examples) directory.

## Documentation

Documentation can be found by checking the [`docs/`](docs) directory.

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

Output for the above test:
```
============================
  Testing Integer Equality
============================
✔ integers of same value are equal

SUCCESS! All tests (1) passing with no tests failing. Returned with exit code "0".
```

A snippet from a seperate test:
```
======================
  Testing Assertions
======================
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



## Contact

Questions? Comments? Suggestions? <br/>
Open an issue, make a pull request!
<br/><br/>
Or, you can email me at: luis@serebii.io

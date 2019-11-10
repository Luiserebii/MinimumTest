# Mint
![mint-image](https://ezeequit-wirral.co.uk/wp-content/uploads/2015/06/mint.jpg)

Mint is a minimal header-only C++ test runner.

## Installation
A `CMakeLists.txt` file has been added for simple linking with CMake. For more on this, check the [`examples/`](examples) directory.

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

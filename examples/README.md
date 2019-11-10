# Examples

## Minimal

Minimal examples are run through simply compiling the files, or running the `c.sh` script included.

## CMake

CMake examples are run through a conveniently included `BUILD` script, or running the following:

```bash
#!/bin/bash

if [ ! -d build ]; then
        mkdir build
fi

# Navigate to build
cd build

# Run CMake
cmake ..

# Make
make
```

#!/bin/bash

# Run minimal examples
cd ../examples/minimal/simple
./c.sh

cd ../assertions
./c.sh

# Run cmake examples
cd ../../cmake/simple
./BUILD

cd ../assertions
./BUILD

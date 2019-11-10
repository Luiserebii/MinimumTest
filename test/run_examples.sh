#!/bin/bash

# Run minimal examples
cd ../examples/minimal/simple
./c.sh

echo "";

cd ../assertions
./c.sh

echo "";

# Run cmake examples
cd ../../cmake/simple
./BUILD

echo "";

cd ../assertions
./BUILD

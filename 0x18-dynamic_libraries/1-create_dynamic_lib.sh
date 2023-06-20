#!/bin/bash

# Compile the source code files into object files
gcc -c -Wall -Werror -fPIC main.c

# Create the dynamic library
gcc -shared -o libmain.so main.o

# Clean up the object files
rm main.o

# Move the library file to the desired location
mv libmain.so /path/to/destination

echo "Dynamic library created successfully!"


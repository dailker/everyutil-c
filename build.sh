#!/bin/bash

set -e

# Check for dependencies
command -v gcc >/dev/null 2>&1 || { echo "Error: gcc is required but not installed."; exit 1; }
command -v make >/dev/null 2>&1 || { echo "Error: make is required but not installed."; exit 1; }
command -v pkg-config >/dev/null 2>&1 || { echo "Warning: pkg-config not found, skipping .pc file installation."; }

# Create build directory
mkdir -p build

# Build the library and tests
make clean
make all

# Run tests
echo "Running tests..."
find build/testExecutables -type f -name '*.exe' -print | while read exe; do
    echo "Running $exe"
    "$exe"
done

# Install (optional)
echo "Installing library to /usr/local (use PREFIX=/custom/path make install to change)..."
make install PREFIX=/usr/local

echo "Build and installation complete."
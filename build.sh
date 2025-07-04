#!/bin/sh

# Exit on any error
set -e

# Clean up m4 and build directories if they exist
echo "Cleaning up m4 and build directories..."
[ -d m4 ] && rm -rf m4
[ -d build ] && rm -rf build

# Function to detect package manager and install dependencies
install_dependencies() {
  if command -v pacman >/dev/null 2>&1; then
    # MSYS2
    echo "Detected MSYS2. Installing dependencies with pacman..."
    pacman -S --noconfirm autoconf gcc make
  elif command -v apt-get >/dev/null 2>&1; then
    # Ubuntu/Debian
    echo "Detected Ubuntu/Debian. Installing dependencies with apt-get..."
    sudo apt-get update && sudo apt-get install -y autoconf gcc make
  elif command -v dnf >/dev/null 2>&1; then
    # Fedora/RHEL
    echo "Detected Fedora/RHEL. Installing dependencies with dnf..."
    sudo dnf install -y autoconf gcc make
  elif command -v brew >/dev/null 2>&1; then
    # macOS with Homebrew
    echo "Detected Homebrew. Installing dependencies with brew..."
    brew install autoconf gcc make
  else
    echo "Error: No supported package manager found (pacman, apt-get, dnf, or brew)."
    exit 1
  fi
}

# Check for required tools and install if missing
for tool in autoconf gcc make; do
  if ! command -v $tool >/dev/null 2>&1; then
    echo "$tool not found. Attempting to install dependencies..."
    install_dependencies
    break
  fi
done

# Run autoreconf to generate configure script
echo "Running autoreconf..."
autoreconf --install

# Run configure
echo "Running configure..."
./configure

# Build the project
echo "Building project..."
make clean
make

# Run tests
echo "Running tests..."
make test

echo "Build and test completed successfully."
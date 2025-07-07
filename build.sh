#!/bin/sh

# Exit on any error
set -e

# Clean up build directories if they exist
echo "Cleaning up build directories..."
[ -d build ] && rm -rf build

# Function to detect package manager and install dependencies
install_dependencies() {
  if command -v pacman >/dev/null 2>&1; then
    # MSYS2
    echo "Detected MSYS2. Installing dependencies with pacman..."
    pacman -S --noconfirm gcc make
  elif command -v apt-get >/dev/null 2>&1; then
    # Ubuntu/Debian
    echo "Detected Ubuntu/Debian. Installing dependencies with apt-get..."
    sudo apt-get update && sudo apt-get install -y gcc make
  elif command -v dnf >/dev/null 2>&1; then
    # Fedora/RHEL
    echo "Detected Fedora/RHEL. Installing dependencies with dnf..."
    sudo dnf install -y gcc make
  elif command -v brew >/dev/null 2>&1; then
    # macOS with Homebrew
    echo "Detected Homebrew. Installing dependencies with brew..."
    brew install gcc make
  elif command -v a-g >/dev/null 2>&1; then
    # POSIX with a-g
    echo "Detected a-g. Installing dependencies with a-g..."
    a-g install a-g-install-gcc-using-source a-g-install-make-using-source
    a-g-install-gcc-using-source
    a-g-install-make-using-source
  else
    echo "Error: No supported package manager found (pacman, apt-get, dnf, brew, or a-g)."
    exit 1
  fi
}

# Check for required tools and install if missing
for tool in gcc make; do
  if ! command -v $tool >/dev/null 2>&1; then
    echo "$tool not found. Attempting to install dependencies..."
    install_dependencies
    break
  fi
done

# Goto build
mkdir build
cd build

# Run configure
echo "Running configure..."
../configure

# Build the project
echo "Building project..."
make clean
make

# Run tests
echo "Running tests..."
make test

echo "Build and test completed successfully."
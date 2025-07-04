# everyutil-c

A comprehensive C utility library with logic functions and cross-platform support.

## Features

- ✅ Header files with proper API declarations
- ✅ Source implementation in C
- ✅ Test files with validation cases
- ✅ Windows DLL export support
- ✅ Cross-platform compatibility

## Building

### Quick Start (Recommended)
```bash
# Use the automated build script
bash build.sh
```

### Manual Build Options

#### Using Makefile (Direct)
```bash
make all     # Build everything (static, shared, tests)
make static  # Build static library only
make shared  # Build shared library only
make test    # Build and run tests
make clean   # Clean build artifacts
```

#### Using Autotools
```bash
autoreconf --install
./configure
make
make test
```

#### Using CMake (if available)
```bash
mkdir build && cd build
cmake ..
make
```

### Troubleshooting

**CMake not found?**
- Use `bash build.sh` or `make all` instead
- The build script will auto-install dependencies on MSYS2/Linux

**Missing dependencies?**
- MSYS2: `pacman -S autoconf gcc make`
- Ubuntu/Debian: `sudo apt-get install autoconf gcc make`
- Fedora: `sudo dnf install autoconf gcc make`

## How to Code

You can easily add it to your code when you build the project. Nothing messy ;)
```c
#include <everyutil/some_header.h>  // adjust based on actual headers

int main() {
    call_some_function(); 
    return 0;
}
```

## License

MIT License - Ilker Ozturk (GitHub@dailker) 2024
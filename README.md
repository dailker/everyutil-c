# everyutil-c

A comprehensive C utility library with logic functions and cross-platform support.

## Features

- ✅ Header files with proper API declarations
- ✅ Source implementation in C
- ✅ Test files with validation cases
- ✅ Windows DLL export support
- ✅ Cross-platform compatibility

## Building

### Using CMake
```bash
mkdir build && cd build
cmake ..
make
```

### Using Makefile
```bash
make shared  # Build shared library
make static  # Build static library
make tests   # Build test programs
```

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
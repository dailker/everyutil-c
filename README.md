# everyutil-c

[![License: MIT](https://img.shields.io/badge/License-MIT-blue.svg)](https://opensource.org/licenses/MIT)
[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)]()
[![Contributions Welcome](https://img.shields.io/badge/contributions-welcome-orange.svg)](https://github.com/dailker/everyutil-c/issues)

A robust and comprehensive C utility library designed for developers seeking reliable logic functions and seamless cross-platform support. Built with simplicity and performance in mind, `everyutil-c` empowers your projects with reusable, well-tested utilities.

## Features
- ✅ **Clean API**: Well-documented header files with clear function declarations
- ✅ **High Performance**: Optimized C source implementations
- ✅ **Thorough Testing**: Extensive test suite to ensure reliability
- ✅ **Cross-Platform**: Supports Windows (DLL export), Linux, and macOS
- ✅ **Flexible Build Options**: Supports Makefile, Autotools, and CMake for easy integration

## Recent Updates
🎉 **Latest Achievement: Gitty Draw!**  
We’ve recently enhanced `everyutil-c` with streamlined build instructions and refactored array utility functions for better performance and maintainability. Check out the [latest commit](https://github.com/dailker/everyutil-c/commit/841ec06) to see the improvements! Ready to contribute? Dive into our [open issues](https://github.com/dailker/everyutil-c/issues) or submit a PR to join the journey!

## Getting Started
### Prerequisites
- C compiler (`gcc`, `clang`, or similar)
- Build tools: `make`, `autoconf`, or `cmake`
- Optional: MSYS2 for Windows development

### Building
#### Quick Start (Recommended)
Run the automated build script for a hassle-free setup:
```bash
bash build.sh
```

#### Manual Build Options
**Using Makefile (Direct)**
```bash
make all     # Build static, shared libraries, and tests
make static  # Build static library only
make shared  # Build shared library only
make test    # Build and run tests
make clean   # Clean build artifacts
```

**Using Autotools**
```bash
autoreconf --install
./configure
make
make test
```

**Using CMake**
```bash
mkdir build && cd build
cmake ..
make
```

### Troubleshooting
- **CMake not found?**  
  Use `bash build.sh` or `make all` as alternatives. The build script auto-installs dependencies on MSYS2/Linux.
- **Missing dependencies?**  
  Install required tools:  
  - **MSYS2**: `pacman -S autoconf gcc make`  
  - **Ubuntu/Debian**: `sudo apt-get install autoconf gcc make`  
  - **Fedora**: `sudo dnf install autoconf gcc make`

## Using everyutil-c
Integrate `everyutil-c` into your project with ease:
```c
#include <everyutil/some_header.h>  // Replace with actual header

int main() {
    call_some_function();  // Call utility functions
    return 0;
}
```
Link the library during compilation (e.g., `-leveryutil` for shared or static library).

## Contributing
We welcome contributions! To get started:
1. Fork the repository
2. Create a feature branch (`git checkout -b feature/awesome-feature`)
3. Commit your changes (`git commit -m 'Add awesome feature'`)
4. Push to the branch (`git push origin feature/awesome-feature`)
5. Open a Pull Request

Check out our [contributing guidelines](CONTRIBUTING.md) for more details.

## License
MIT License - © Ilker Ozturk (GitHub: @dailker) 2024

## Acknowledgments
Thank you to all contributors and the open-source community for inspiring and supporting this project. Let’s keep building awesome tools together!

# PowerShell script for building on Windows

    # Check for compilers
    $hasMsvc = Get-Command cl -ErrorAction SilentlyContinue
    $hasGcc = Get-Command gcc -ErrorAction SilentlyContinue
    if (-not $hasMsvc -and -not $hasGcc) {
        Write-Error "No compiler found. Install MSVC or MinGW."
        exit 1
    }

    # Create build directory
    if (-not (Test-Path -Path "build")) {
        New-Item -ItemType Directory -Path "build"
    }

    # Run make
    if ($hasGcc) {
        Write-Host "Using MinGW to build..."
        mingw32-make clean
        mingw32-make all
    } else {
        Write-Host "Using MSVC to build..."
        $env:CC = "cl"
        nmake clean
        nmake all
    }

    # Run tests
    Write-Host "Running tests..."
    # Run all test executables in build/testExecutables/*/*.exe
    Get-ChildItem -Path "build/testExecutables" -Recurse -Filter *.exe | ForEach-Object {
        Write-Host "Running $($_.FullName)"
        & $_.FullName
    }

    # Install (optional)
    Write-Host "Installing to C:\Program Files\everyutil (customize with PREFIX=...)"
    $env:PREFIX = "C:\Program Files\everyutil"
    if ($hasGcc) {
        mingw32-make install
    } else {
        nmake install
    }

    Write-Host "Build and installation complete."
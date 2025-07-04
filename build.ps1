# PowerShell script for building the project on Windows with MSYS2/MinGW
$ErrorActionPreference = "Stop"

# Clean up m4 and build directories if they exist
Write-Host "Cleaning up m4 and build directories..."
if (Test-Path -Path "m4") { Remove-Item -Path "m4" -Recurse -Force }
if (Test-Path -Path "build") { Remove-Item -Path "build" -Recurse -Force }

# Function to check if a command exists
function Test-Command {
    param (
        [string]$Command
    )
    return Get-Command $Command -ErrorAction SilentlyContinue
}

# Check and install dependencies
$tools = @("gcc", "make", "autoreconf")
foreach ($tool in $tools) {
    if (-not (Test-Command $tool)) {
        Write-Host "Installing dependencies with pacman..."
        & pacman -S --noconfirm autoconf gcc make
        if ($LASTEXITCODE -ne 0) {
            Write-Error "$tool not found and installation failed. Ensure MSYS2 is installed and pacman is accessible."
            exit 1
        }
        break
    }
}

# Run autoreconf to generate configure script
Write-Host "Running autoreconf..."
autoreconf --install

# Run configure
Write-Host "Running configure..."
.\configure

# Build the project
Write-Host "Building project..."
make clean
make

# Run tests
Write-Host "Running tests..."
make test

Write-Host "Build and test completed successfully."
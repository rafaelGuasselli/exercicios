# compile.ps1
param(
    [switch]$DebugMode, # Renamed to avoid system conflict
    [Parameter(Position=0)]
    [string]$File
)

$ErrorActionPreference = "Stop"

if (-not $File) {
    Write-Error "Usage: .\scripts\compile.ps1 [-DebugMode] <file>"
    exit 1
}

if (-not (Test-Path $File)) {
    Write-Error "File not found: $File"
    exit 1
}

if (-not (Test-Path "./temp")) {
    New-Item -ItemType Directory -Path "./temp" | Out-Null
}

$gpp_flags = @()
if ($DebugMode) {
    $gpp_flags += "-DDEBUG"
}

& g++ $gpp_flags $File -o ./temp/a.exe
Write-Host "Compiled successfully: ./temp/a.exe" -ForegroundColor Green
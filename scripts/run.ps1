# run.ps1
param(
    [switch]$DebugMode, # Renamed to avoid system conflict
    [Parameter(Position=0)]
    [string]$File
)

$ErrorActionPreference = "Stop"

if (-not $File) {
    Write-Error "Usage: .\scripts\run.ps1 [-DebugMode] <file>"
    exit 1
}

if (-not (Test-Path $File)) {
    Write-Error "File not found: $File"
    exit 1
}

$ext = [System.IO.Path]::GetExtension($File).ToLower()
$inputFile = "./temp/in"

if (-not (Test-Path $inputFile)) {
    New-Item -ItemType File -Path $inputFile | Out-Null
}

switch ($ext) {
    ".py" {
        $py = if (Get-Command python -ErrorAction SilentlyContinue) { "python" } 
              else { "python3" }
        if (-not $py) { Write-Error "Python not found"; exit 1 }
        
        Get-Content $inputFile | & $py $File
    }
    ".cpp" {
        # Pass the renamed flag to the compile script
        & .\scripts\compile.ps1 -DebugMode:$DebugMode -File $File
        
        if (-not (Test-Path "./temp/a.exe")) {
            Write-Error "Executable not found."
            exit 1
        }

        Get-Content $inputFile | & ./temp/a.exe
    }
    Default {
        Write-Error "Unsupported extension: $ext"
        exit 1
    }
}
#!/usr/bin/env bash
set -euo pipefail

# Accept file from $file env or first arg
file=${file:-${1:-}}

if [[ -z "${file}" ]]; then
  echo "Usage: scripts/run.sh <file> (or set \$file)" >&2
  exit 1
fi

if [[ ! -f "$file" ]]; then
  echo "File not found: $file" >&2
  exit 1
fi

ext=${file##*.}
ext=${ext,,} # lowercase

case "$ext" in
  py)
    if command -v python >/dev/null 2>&1; then
      py=python
    elif command -v python3 >/dev/null 2>&1; then
      py=python3
    else
      echo "Python interpreter not found (python or python3)" >&2
      exit 1
    fi
    $py "$file" < temp/in
    ;;
  cpp)
	g++ $file -o ./temp/a.out
    if [[ ! -x ./temp/a.out ]]; then
      echo "Missing executable ./temp/a.out. Compile first (e.g., scripts/compile.sh $file)." >&2
      exit 1
    fi
    ./temp/a.out < temp/in
    ;;
  *)
    echo "Unsupported file extension: .$ext (expected .py or .cpp)" >&2
    exit 1
    ;;
esac

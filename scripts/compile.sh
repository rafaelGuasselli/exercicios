set -euo pipefail

debug=false
file=${file:-}

if [[ $# -gt 0 ]]; then
  while [[ $# -gt 0 ]]; do
    case "$1" in
      --debug|-d)
        debug=true
        shift
        ;;
      --)
        shift
        break
        ;;
      -*)
        echo "Unsupported option: $1" >&2
        exit 1
        ;;
      *)
        if [[ -z "$file" ]]; then
          file=$1
        fi
        shift
        ;;
    esac
  done
fi

if [[ -z "$file" && $# -gt 0 ]]; then
  file=$1
  shift
fi

if [[ -z "$file" ]]; then
  echo "Usage: scripts/compile.sh [--debug|-d] <file>" >&2
  exit 1
fi

if [[ ! -f "$file" ]]; then
  echo "File not found: $file" >&2
  exit 1
fi

gpp_flags=()
if [[ "$debug" == true ]]; then
  gpp_flags+=("-DDEBUG")
fi

g++ "${gpp_flags[@]}" "$file" -o ./temp/a.out

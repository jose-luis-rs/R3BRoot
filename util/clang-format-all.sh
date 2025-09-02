#!/usr/bin/env bash
set -euo pipefail

if command -v clang-format-15 >/dev/null 2>&1; then
    CLANG_FORMAT=clang-format-15
elif command -v clang-format-18 >/dev/null 2>&1; then
    CLANG_FORMAT=clang-format-18
elif command -v clang-format >/dev/null 2>&1; then
    CLANG_FORMAT=clang-format
else
    echo "Error: clang-format not found." >&2
    exit 1
fi

find . -type f \( -name "*.cpp" -o -name "*.cxx" -o -name "*.C" -o -name "*.h" \) \
    ! -path "./macros" ! -path "./sofia" ! -path "./frs" ! -path "./asyeos" ! -path "./glad-tpc" -print0 |
    xargs -0 -L 1 "$CLANG_FORMAT" -i

echo "Use git add -A ; git commit -m \"clang-format all files\" --author=\"white space <whitespace@example.com>\" to commit changes."

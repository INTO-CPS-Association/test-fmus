#!/usr/bin/env bash
set -euo pipefail

root=${1%/}
validator=${FMPY_PYTHON:-python}
"$validator" -c 'import fmpy'
test -d "$root/fmi2"
test -d "$root/fmi3"

printf '## FMU conformance diagnostics\n\n'
printf 'FMPy checks the metadata against FMI rules. Findings do not by themselves establish whether an FMU works with Maestro.\n\n'
count=0
while IFS= read -r fmu; do
    count=$((count + 1))
    relative=${fmu#"$root"/}
    printf '### `%s`\n\n' "$relative"
    if output=$("$validator" -m fmpy validate "$fmu" 2>&1); then
        printf 'No problems reported by FMPy.\n\n'
    elif [[ "$output" =~ ^[0-9]+\ problems?\ were\ found: ]]; then
        printf 'FMPy reported the following findings:\n\n```text\n%s\n```\n\n' "$output"
    else
        printf 'FMPy could not complete validation:\n\n```text\n%s\n```\n\n' "$output"
    fi
done < <(find "$root/fmi2" "$root/fmi3" -type f -name '*.fmu' | LC_ALL=C sort)

if (( count == 0 )); then
    echo 'No FMUs found to validate' >&2
    exit 1
fi
#!/bin/bash
# For every file in 'test/input', run atual.py using the file as input and compare the output
# with the corresponding expected output file in 'test/output' (which has the same filename).

total=0
passed=0

for input_file in test/input/*; do
	total=$((total + 1))
	base=$(basename "$input_file")
	expected_file="test/output/$base"
	echo "Testing $input_file"

	# Run atual.py and capture its output
	python3 atual.py < "$input_file" > tmp.out

	if [ ! -f "$expected_file" ]; then
		echo "  Expected file '$expected_file' not found."
		continue
	fi

	# Compare the actual output with the expected output
	if diff -q tmp.out "$expected_file" > /dev/null; then
		echo "  PASSED"
		passed=$((passed + 1))
	else
		echo "  FAILED"
		diff tmp.out "$expected_file"
	fi
done

echo "Total passed: $passed out of $total"
rm -f tmp.out

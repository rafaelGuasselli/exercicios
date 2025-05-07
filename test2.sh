#!/bin/bash
# For every file in 'secret' that does not end with ".ans",
# run atual.py using the file as input and compare the output
# with the corresponding expected output file (which is assumed to be the same filename with ".ans" appended).

for input_file in secret/*.in; do

	without_ext="${input_file%.in}"
	expected_file="${without_ext}.ans"
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
	else
		echo "  FAILED"
		diff tmp.out "$expected_file"
	fi
done

rm -f tmp.out
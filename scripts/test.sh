#!/bin/bash

# Directories
input_dir="./test/input"
output_dir="./test/output"
executable="./a.out"

g++ -x c++ -g -O2 -std=gnu++20 -static ./atual.cpp

passed=0
total=0

max_time=0
slowest_test=""

# Check if executable exists
if [[ ! -x "$executable" ]]; then
	echo "Error: $executable not found or not executable."
	exit 1
fi

# Iterate over input files
for input_file in "$input_dir"/*; do
	# Extract the base name of the input file
	base_name=$(basename "$input_file")
	total=$((total + 1))
	
	# Define the corresponding output file
	expected_output_file="$output_dir/$base_name"
	
	# Check if the expected output file exists
	if [[ ! -f "$expected_output_file" ]]; then
		echo "Warning: Expected output file $expected_output_file not found. Skipping."
		continue
	fi

	# Measure execution time using nanoseconds and convert to milliseconds
	start=$(date +%s%N)
	actual_output=$("$executable" < "$input_file")
	end=$(date +%s%N)
	duration_ns=$(( end - start ))
	duration_ms=$(( duration_ns / 1000000 ))
	
	# Update slowest test if necessary (using ms)
	if (( duration_ms > max_time )); then
		max_time=$duration_ms
		slowest_test=$base_name
	fi
	
	# Compare the actual output with the expected output
	if diff <(echo "$actual_output") "$expected_output_file" > /dev/null; then
		echo "Test passed for $base_name"
		passed=$((passed + 1))
	else
		echo "Test failed for $base_name"
		echo "Diff:"
		diff <(echo "$actual_output") "$expected_output_file"
	fi
done

echo "Tests passed: $passed out of $total"
echo "Slowest test: $slowest_test with execution time: ${max_time} ms"
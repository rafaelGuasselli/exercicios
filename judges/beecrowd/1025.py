import bisect

count = 1
while True:
	n, q = map(int, input().split())
	if n == q == 0:
		break

	array = []
	for i in range(n):
		val = int(input())
		array.append(val)
	array.sort()

	print(f"CASE# {count}:")
	count += 1
	
	for i in range(q):
		val = int(input())
		index = bisect.bisect_left(array, val)
		if index < len(array) and array[index] == val:
			print(f"{val} found at {index + 1}")
		else:
			print(f"{val} not found")
from math import log2, ceil, floor
t = int(input())
while t:
	t-=1
	size = int(input())
	answer = 1
	maxSize = 1

	while True:
		if maxSize >= size:
			print(answer)
			break
		answer += 1
		maxSize = 2 * (maxSize + 1)
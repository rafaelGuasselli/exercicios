def choose(n, k):
	if (k == 0):
		return 1
	elif (n <= 0): return 0

	return n * choose(n-1, k-1)/k

n = int(input())
val = 1 + choose(n, 2) + choose(n, 4)
print("{:d}".format(int(val)))
k, n = map(int, input().split())

minN = 2 * k - 1
maxN = 3 * k

if minN <= n <= maxN:
	j = 3 * k - n
	i = k - j

	if i < 0:
		s = "X-" * (j-1)
		s = s[:-1]
	else:
		s = "-X-" * i + "-X" * j

	print(s)
else:
	print("*")
mod = 998244353
t = int(input())



while t:
	t-=1
	n = int(input())
	a = list(map(int, input().split()))

	a.sort()

	suffix = [0] * n
	suffix[-1] = a[-1]
	for i in range(n-2, -1, -1):
		suffix[i] = suffix[i+1]+a[i]

	total = 0
	for i in range(1, n):
		total = (total + suffix[i]) % mod

	for i in range(n):
		total = (total - (n-1) * a[i]) % mod

	print(total)
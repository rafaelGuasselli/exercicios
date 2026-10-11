from math import pow
t = int(input())
while t:
	t-=1
	n = int(input())
	a = list(map(int, input().split()))

	xn = 0
	for i in range(n):
		xn += pow(-1, i) * 2 * a[i]


	p = xn/2
	print(int(p))
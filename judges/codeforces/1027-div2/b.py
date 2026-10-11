from math import pow
t = int(input())
while t:
	t-=1
	n = int(input())
	a = list(map(int, input().split()))

	sp = a[0]
	sm = a[0]
	biggest = a[0]
	for i in range(1, n):
		biggest = max([a[i]-sm, a[i]+sp, biggest])
		sp = max(sp+(a[i]-sp), sp+(a[i]+sp))
		sm = min(sm+(a[i]-sm), sm+(a[i]+sm))
	print(biggest)
		
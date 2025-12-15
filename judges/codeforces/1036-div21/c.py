from math import gcd
t=int(input())
while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))

	x = 1
	for i in range(n-2, -1, -1):
		if a[i+1]%a[i] != 0:
			if x == 1:
				x = a[i]//gcd(a[i+1], a[i])
			else:
				b = a[i]//gcd(a[i+1], a[i])
				x = (x*b)//gcd(x, b)
	print(x)

#14 14 14 28 28 24360 255780

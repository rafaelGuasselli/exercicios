t=int(input())
while t:
	t-=1
	a = list(map(int, input().split()))

	a.sort()
	total = -sum(a)+2*a[-1]
	print(total)
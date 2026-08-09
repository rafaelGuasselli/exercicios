t=int(input())
while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))
	r=[0]*n

	soma = 0
	minimo=1e18
	for i in range(0, len(a)):
		soma += a[i]
		minimo = min(minimo, soma//(i+1))
		r[i] = minimo
	
	print(*r)
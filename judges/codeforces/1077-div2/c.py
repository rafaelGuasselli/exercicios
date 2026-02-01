t=int(input())
while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))
	b = a.copy()
	b.sort()

	m0 = min(a)
	m1 = max(a)
	maximo=max(a)+1
	for i in range(n):
		if a[i] != b[i]:
			da = max(abs(m0-a[i]), abs(m1-a[i]))
			db = max(abs(m0-b[i]), abs(m1-b[i]))
			maximo = min([maximo, da, db])
	
	if maximo == m1+1:
		print(-1)
	else:
		print(maximo)
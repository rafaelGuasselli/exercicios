t=int(input())
while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))

	a.append(a[0])
	b=[]
	for i in range(n):
		b.append(max(a[i], a[i+1]))
	
	b.sort()
	print(sum(b[:n-1]))
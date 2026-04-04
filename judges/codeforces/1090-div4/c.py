t=int(input())
while t:
	t-=1
	n = int(input())
	r=[]

	for i in range(n):
		r.append((3*n-i*2-1, 3*n-i*2, i+1))
	
	for i in r:
		print(*i, end=" ")
	print()

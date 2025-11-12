t=int(input())
while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))

	a.sort()
	yes=True
	for i in range(n-1):
		if i%2 and a[i] != a[i+1]:
			yes=False

	print("YES" if yes else "NO") 

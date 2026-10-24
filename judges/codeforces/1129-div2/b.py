t = int(input())
while t:
	t-=1
	n=int(input())
	a=list(map(int,input().split()))

	res=0
	for i in a:
		if i < n:
			res=n
			break
	print(res)
t=int(input())
while t:
	t-=1
	n, x = map(int, input().split())
	a=list(map(int, input().split()))

	a.sort()
	left=0
	right=n-1
	order=[]
	points=0
	value=0

	while left<=right:
		if value+a[right] >= x:
			order.append(a[right])
			points+=a[right]
			value+=a[right]
			value%=x
			right-=1
		else:
			order.append(a[left])
			value+=a[left]
			value%=x
			left+=1

	print(points)
	print(*order)
			

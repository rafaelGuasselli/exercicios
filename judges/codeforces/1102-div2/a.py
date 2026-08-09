t=int(input())
while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))
	
	a.sort()
	flat=[]
	count = 0
	for i in range(len(a)):
		if a[i] != a[i-1] and i > 0:
			flat.append(count)
			count = 0
		count += 1
	
	if count > 0:
		flat.append(count)
	

	minimo = 1e9
	left = 0
	right = sum(flat)
	for i in flat:
		right -= i
		minimo = min(minimo, max(left, right))
		left += i
	
	print(minimo)
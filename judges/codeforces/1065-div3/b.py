t=int(input())
while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))
	
	firstValue=0
	for i in a:
		if i != -1:
			firstValue = i
			break
	
	total=0
	for i in range(n-1):
		c=0 if a[i+1] == -1 else a[i+1]
		d=0 if a[i] == -1 else a[i]
		total += c-d
	
	if total < 0:
		if a[-1] == -1:
			a[-1] = -total
		
	elif total > 0:
		if a[0] == -1:
			a[0] = total

	
	for i in range(n):
		if a[i] == -1:
			a[i] = 0 
	

	b=[0] * n
	for i in range(n-1):
		b[i] = a[i+1]-a[i]
	
	print(abs(sum(b)))
	print(*a)
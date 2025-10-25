t=int(input())
while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))
 
	preffix=[0]*n
	preffix[0] = a[0]
	for i in range(1, n):
		preffix[i] = max(preffix[i-1], a[i])
	
	for i in range(n):
		if i%2:
			a[i] = preffix[i]
	
	count = 0
	for i in range(n):
		change = 0
		if i%2 == 1: continue
		if i > 0 and i < n-1:
			change = max(max(a[i]-a[i-1]+1, 0), max(a[i]-a[i+1]+1, 0))
		elif i > 0:
			change = max(a[i]-a[i-1]+1, 0)
		else:
			change = max(a[i]-a[i+1]+1, 0)
 
		count += change
	print(count)
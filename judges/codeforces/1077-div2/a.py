t=int(input())
while t:
	t-=1
	n=int(input())
	
	left=1
	right=n
	r=[0]*n
	for i in range(n):
		if i % 2 == 0:
			r[-i-1] = left
			left += 1
		else:
			r[-i-1] = right
			right-=1
	print(*r)
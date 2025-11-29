t=int(input())
while t:
	t-=1
	n, k= map(int, input().split())
	a=list(map(int,input().split()))
	b=list(map(int,input().split()))

	left = [0] * n
	right = [0] * n
	acc=0
	maxV = -1e9
	for i in range(n):
		acc += a[i]
		if acc >= maxV:
			maxV = acc
		acc=max(0, acc)
		left[i] = acc
	
	acc=0
	for i in range(n-1, -1, -1):
		acc += a[i]
		acc=max(0, acc)
		right[i] = acc

	if k%2 == 0:
		print(maxV)
	else:
		for i in range(n):
			r = 0 if i+1 >= n else right[i+1]
			l = 0 if i-1 < 0 else left[i-1]
			val = a[i] + b[i] + l + r
			maxV = max(val, maxV)
		print(maxV)





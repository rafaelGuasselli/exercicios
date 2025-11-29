t=int(input())
while t:
	t-=1
	n,c,d=map(int, input().split())
	a=list(map(int, input().split()))
	a.sort()
	a.reverse()

	prefix = [0] * (max(d, n)+2)
	for i in range(1, n+1):
		prefix[i]=prefix[i-1]+a[i-1]
	
	for i in range(n+1, d+2):
		prefix[i]=prefix[i-1]

	rk = -1
	for k in range(d, -1, -1):
		block = k+1
		rep = d//block
		res = d%block
		val = rep * prefix[block] + prefix[res]

		if val >= c:
			rk = k
			break
	
	if sum(a[:d]) >= c:
		print("Infinity")
	elif rk >= 0:
		print(rk)
	else:
		print("Impossible")
t = int(input())
while t:
	t-=1
	n, k = map(int, input().split())
	a=list(map(int,input().split()))

	count = [0]*n
	for i in a:
		if i < n:
			count[i]+=1

	prefix = [0] * n
	prefix[0] = count[0]
	for i in range(1, n):
		prefix[i] = prefix[i-1]+count[i]

	maxMex = 0
	for i in range(n):
		if count[i] > 0 and prefix[i] >= (i+1)*k:
			maxMex=i+1
		else:
			break
	print(maxMex)
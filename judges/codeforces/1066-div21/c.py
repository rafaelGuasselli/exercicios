t=int(input())
while t:
	t-=1
	n, k, q = map(int, input().split())

	array=[0]*n
	for i in range(q):
		c, l, r = map(int, input().split())
		for j in range(l-1, r):
			if array[j] == 0:
				array[j] = c
			elif array[j] != c:
				array[j] = 3
	

	for i in range(n):
		if array[i] == 0:
			array[i] = k
		elif array[i] == 1:
			array[i] = k
		elif array[i] == 2:
			array[i] = i%k
		else: 
			array[i] = k+1
	print(*array)
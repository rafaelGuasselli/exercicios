def calcMaxVal(n):
	m = 0
	for i in range(1, n+1):
		m += n//i * i 
	return m

t = int(input())
while t:
	t-=1
	n = int(input())

	a = 1
	b = 1000
	rc = 0
	while a <= b:
		c = a + (b-a)//2

		if calcMaxVal(c) >= n:
			rc = c
			b = c-1
		else:
			a = c+1

	array = []
	size = rc
	total = n
	curr=1

	while total > 0:
		max_bags = min(rc // size, total // size)
		for i in range(max_bags):
			array.extend([curr] * size)
			curr+=1
			total -= size
		size-=1

	print(rc)
	print(*array)
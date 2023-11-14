while True:
	x = input()
	a, b, c = map(int, x.split())
	first = True
	if a == 0:
		break
	A = {}
	for i in range(1, c+1):
		A[i] = 0
	for _ in range(a):
		n = [int(e) for e in input().split()]
		for e in n:
			A[e]+=1
	d = 999999999999
	for e in A:
		if A[e]<d:
			d = A[e]
	for e in A:
		if A[e]==d:
			if first:
				print(e, end="")
				first = False
			else:
				print(f" {e}", end="")
	print()
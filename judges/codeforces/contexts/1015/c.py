t = int(input())
while t:
	t-=1
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))
	
	posA = {}
	match = {}
	meios = []
	possivel = 1
	for i in range(n):
		posA[a[i]] = i
		if a[i] == b[i]:
			meios.append(i)
		
		if a[i] not in match:
			match[b[i]] = a[i]
		elif match[a[i]] != b[i]:
			possivel = 0
	
	if not possivel or len(meios) > n%2:
		print(-1)
	else:
		movimentos = []
		if len(meios) == 1 and meios[0] != n//2:
			mi, mj = meios[0], n//2
			movimentos.append((mi, mj))
			a[mi], a[mj] = a[mj], a[mi]
			b[mi], b[mj] = b[mj], b[mi]
			posA[a[mi]], posA[a[mj]] = mi, mj

		for i in range(0, n//2):
			if a[i] != b[n-i-1]:
				mi, mj = n-i-1, posA[b[i]]
				movimentos.append((mi, mj))
				a[mi], a[mj] = a[mj], a[mi]
				b[mi], b[mj] = b[mj], b[mi]
				posA[a[mi]], posA[a[mj]] = mi, mj

		print(len(movimentos))
		for m in movimentos:
			i, j = m
			print(f"{i+1} {j+1}")
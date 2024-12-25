n, d = map(int, input().split())
paes = list(map(int, input().split()))

inicio = {}
fim = {}
for i in range(n):
	if (paes[i]-d) >= 0:
		if not inicio[paes[i]-d]: 
			inicio[paes[i]-d] = []
		inicio[paes[i]-d].append(i)

	if not inicio[paes[i]+d]: 
		inicio[paes[i]+d] = []
	fim[paes[i]+d].append(i)
print()
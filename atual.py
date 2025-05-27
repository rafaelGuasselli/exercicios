n = int(input())
a = list(map(int, input().split()))


mudanca = []
prev = 0
for i in range(n):
	if a[i] != 0 and i!=prev:
		mudanca.append((prev, i, a[i]>a[prev]))
		prev = i
mudanca.append((prev, n-1, a[n-1]>a[prev]))

mudancasUnicas = []
mudancaAtual = mudanca[0]
for i in range(1, len(mudanca)):
	p1, n1, c1 = mudanca[i-1]
	p2, n2, c2 = mudanca[i]

	if c1 == c2:
		mudancaAtual = (mudancaAtual[0], n2, c2)
	else:
		mudancasUnicas.append(mudancaAtual)
		mudancaAtual = mudanca[i]
mudancasUnicas.append(mudancaAtual)

if len(mudancasUnicas) > 2:
	print("*")
elif len(mudancasUnicas) == 1:
	possivel = 1
	for i in range(n):
		if a[i] != i+1 and a[i] != 0:
			possivel = 0
			break
		
	if possivel:
		print(*list(range(n, 0, -1)))
	else:
		print("*")
elif len(mudancasUnicas) == 2 and mudancasUnicas[0][2] and not mudancasUnicas[1][2]:
	marcado = [0 for i in range(0, n+1)]
	for i in range(n):
		if a[i] != 0:
			marcado[a[i]] = 1
	
	possivel = 1
	minNext = 0

	for i in range(mudancasUnicas[0][0], mudancasUnicas[0][1]):
		if a[i] == 0:
			while marcado[minNext] and minNext < n-1:
				minNext += 1

			if marcado[minNext]:
				possivel = 0
				break

			a[i] = minNext
			marcado[minNext] = 1
		minNext = a[i]+1

	maxNext = n
	for i in range(mudancasUnicas[1][0]+1, n):
		if a[i] == 0:
			while maxNext > 1 and marcado[maxNext]:
				maxNext -= 1

			if marcado[maxNext]:
				possivel = 0
				break

			a[i] = maxNext
			marcado[maxNext] = 1
		maxNext = a[i]-1

	if possivel:
		print(*a)
	else:
		print("*")

else:
	print("*")
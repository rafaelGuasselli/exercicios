tamanho, qtdPistas = map(int, input().split())

dicas = []
for i in range(0, qtdPistas):
	x, y, distancia = map(int, input().split())
	dicas.append((x, y, distancia, i))

possiveis = []
for l in range(0, tamanho):
	for c in range(0, tamanho):
		for dica in dicas:
			x, y, distancia, i = dica
			if abs(y-l) + abs(x-c) != distancia:
				break
			if i == qtdPistas - 1:
				possiveis.append((l, c))

if len(possiveis) == 1:
	y, x = possiveis[0]
	print("{:n} {:n}".format(x, y))
else:
	print("-1 -1")
def criarListaDeAdjacentes(y, x):
	return [(y-1, x), (y+1, x), (y, x-1), (y, x+1)]

def getValue(matriz, pos):
	y, x = pos
	if x >= 0 and y >= 0 and y < len(matriz) and x < len(matriz[y]):
		return matriz[y][x]
	return False

def floydFill(matriz, pos):
	y, x = pos
	queue = criarListaDeAdjacentes(y, x)
	matriz[y][x] = "T"
	for p in queue:
		if getValue(matriz, p) == "A":
			floydFill(matriz, p)

def ex(entrada):
	qtdLinhas, qtdColunas = map(int, entrada.split())
	tanque = []

	for l in range(0, qtdLinhas):
		linha = [x for x in input()]
		tanque.append(linha)
	
	for y in range(0, qtdLinhas):
		for x in range(0, qtdColunas):
			if getValue(tanque, (y, x)) == "T":
				floydFill(tanque, (y, x))
	
	for l in range(0, qtdLinhas):
		for c in range(0, qtdColunas):
			print(tanque[l][c], end="")
		print()
	

while True:
	entrada = input()
	if entrada == "0 0":
		break
	ex(entrada)
	print()
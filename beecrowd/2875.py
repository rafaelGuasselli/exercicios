def getValue(matriz, pos):
	y, x = pos
	if x >= 0 and y >= 0 and y < len(matriz) and x < len(matriz[y]):
		return matriz[y][x]
	return False

def andar(matriz, pos, caminho, direcao):
	y, x = pos
	if getValue(matriz, (y+1, x)) == 0:

def ex(entrada):
	numLinhas, numColunas = map(int, entrada.split())
	
	pos = (-1, -1)
	matriz = []
	for l in range(0, numLinhas):
		linha = list(map(int, input().split()))
		matriz.append(linha)
		if "X" in linha:
			pos = (l, linha.index("X"))
	

while True:
	try:
		entrada = input()
		ex(entrada)
	except EOFError:
		break
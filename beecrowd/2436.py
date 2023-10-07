def criarListaDeAdjacentes(y, x):
	return [(y-1, x), (y+1, x), (y, x-1), (y, x+1)]

def getValue(matriz, pos):
	y, x = pos
	if x >= 0 and y >= 0 and y < len(matriz) and x < len(matriz[y]):
		return matriz[y][x]
	return False

def robo(matriz, pos):
	y, x = pos
	queue = criarListaDeAdjacentes(y, x)
	ultimoY, ultimoX = y, x
	matriz[y][x] = 0
	
	while len(queue) > 0:
		lado = queue.pop()
		if getValue(matriz, lado):
			y, x = lado
			matriz[y][x] = 0
			queue.clear()
			queue.extend(criarListaDeAdjacentes(y, x))
			ultimoY, ultimoX = y, x
			
	return (ultimoY, ultimoX)

numeroLinhas, numeroColunas = map(int, input().split())
roboY, roboX = map(int, input().split())

matriz = []
for i in range(0, numeroLinhas):
	linha = list(map(int, input().split()))
	matriz.append(linha)

finalY, finalX = robo(matriz, (roboY-1, roboX-1))
print("{:n} {:n}".format(finalY+1, finalX+1))

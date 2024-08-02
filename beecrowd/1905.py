def getValue(matriz, pos):
	y, x = pos
	if y >= 0 and x >= 0 and y < len(matriz) and x < len(matriz[y]):
		return matriz[y][x]
	else:
		return "3"

def criarLookupQueue(y, x):
	return [(y, x + 1), (y, x - 1), (y + 1, x), (y - 1, x)]

def verificarSeHaSaida(matriz, pos, saida):
	queue = [pos]
	while (len(queue) > 0):
		y, x = lookPos = queue.pop()
		if getValue(matriz, lookPos) == "0":
			matriz[y][x] = "2"
			queue.extend(criarLookupQueue(y, x))
			if lookPos == saida:
				return True
	return False

def ex():
	matriz = []
	linha = input().split()
	while (len(linha) == 0):
		linha = input().split()
	matriz.append(linha)
	for l in range(0, 4):
		linha = input().split()
		matriz.append(linha)
	
	print("COPS" if verificarSeHaSaida(matriz, (0, 0), (4, 4)) else "ROBBERS") 
	

qtdTestes = int(input())
for i in range(0, qtdTestes):
	ex()
def getValue(matriz, pos):
	y, x = pos
	if x >= 0 and y >= 0 and y < len(matriz) and x < len(matriz[y]):
		return matriz[y][x]
	return -1000000

def contarBandeiras(matriz, pos):
	y, x = pos
	total = 0
	valorAtual = getValue(matriz, (y, x))
	matriz[y][x] = -100000

	for pos in [(y-1, x), (y+1, x), (y, x-1), (y, x+1)]:
		if getValue(matriz, pos) >= valorAtual:
			total += contarBandeiras(matriz, pos)
	return total + 1

tamanho = int(input())
inicioY, inicioX = list(map(int, input().split()))

matriz = []
for i in range(0, tamanho):
	linha = list(map(int, input().split()))
	matriz.append(linha)

print(contarBandeiras(matriz, (inicioY-1, inicioX-1)))
from math import ceil
def somaAdjacentes(matrix, pos):
	y, x = pos
	total = 0
	if y-1 >= 0:
		total += ceil(matrix[y-1][x] / 9)
	if x-1 >= 0:
		total += ceil(matrix[y][x-1] / 9)
	if y+1 < len(matrix):
		total += ceil(matrix[y+1][x] / 9)
	if x+1 < len(matrix[y]):
		total += ceil(matrix[y][x+1] / 9)
	return total

def ex(entrada):
	numeroLinhas, numeroColunas = map(int, entrada.split())
	matrix = []
	for i in range(0, numeroLinhas):
		linha = list(map(int, input().split()))
		matrix.append(linha)
	
	for l in range(0, numeroLinhas):
		for c in range(0, numeroColunas):
			if matrix[l][c] == 1:
				print(9, end="")
			if matrix[l][c] == 0:
				print(somaAdjacentes(matrix, (l, c)), end="")
		print()
	
while True:
	try:
		entrada = input()
		ex(entrada)
	except EOFError:
		break
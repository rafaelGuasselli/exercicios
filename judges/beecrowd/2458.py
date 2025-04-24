import sys
sys.setrecursionlimit(10**8)

def dfs(pos, matrix, profundidade, count, memo):
	y, x = pos
	valor = getValue(pos, matrix)
	if valor == False:
		memo[count] = False
		return 0
	elif valor.isdigit():
		if valor == count:
			memo[count] = True
			return profundidade
		elif not valor in memo or memo[valor]:
			memo[count] = True
			return profundidade
		else:
			memo[count] = False
			return 0

	matrix[y][x] = str(count)
	if valor == "V":
		return dfs((y+1, x), matrix, profundidade+1, count, memo)
	elif valor == "A":
		return dfs((y-1, x), matrix, profundidade+1, count, memo)
	elif valor == ">":
		return dfs((y, x+1), matrix, profundidade+1, count, memo)
	elif valor == "<":
		return dfs((y, x-1), matrix, profundidade+1, count, memo)

def getValue(pos, matrix):
	y, x = pos
	if y >= 0 and y < len(matrix) and x >= 0 and x < len(matrix[y]):
		return matrix[y][x]
	return False
	
tamanho = int(input())
matrix = []

for l in range(tamanho):
	linha = input()
	matrix.append(list(linha))
		
qtd = 0
count = 0
memo = {}
for l in range(tamanho):
	for c in range(tamanho):
		if not matrix[l][c].isdigit():
			count += 1
			qtd += dfs((l, c), matrix, 0, str(count), memo)

print(qtd)
def checar(matriz):
	indiceFimZeros = -1
	for l in range(0, qtdLinha):
		for c in range(0, qtdColuna):
			if matriz[l][c] != "0":
				if c <= indiceFimZeros:
					return "N"
				indiceFimZeros = max(indiceFimZeros, c)
				break
			if c == qtdColuna - 1:
				indiceFimZeros = qtdColuna
	return "S"

qtdLinha, qtdColuna = map(int, input().split())
matriz = []

for i in range(0, qtdLinha):
	linha = input().split()
	matriz.append(linha)

print(checar(matriz))
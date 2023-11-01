qtdLinha, qtdColuna = map(int, input().split())

matriz = []
indiceFimZeros = -1

for i in range(0, qtdLinha):
	linha = input().split()
	matriz.append(linha)

valido = True
#Itera pela matriz
#Verifica se a linha atual tem não zeros antes da linha anterior
#Atualiza o indice onde começa os zeros
#Repete
for l in range(0, qtdLinha):
	indicefimZeroLocal = -1
	fimZero = False
	for c in range(0, qtdColuna):
		if matriz[l][c] != "0" and c <= indiceFimZeros:
			valido = False
			break

		if matriz[l][c] != "0":
			fimZero = True

		if not fimZero:
			indicefimZeroLocal = c + 1
	if not valido:
		break
	indiceFimZeros = max(indiceFimZeros, indicefimZeroLocal)
print("S" if valido else "N")
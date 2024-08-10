numeroLinhas, numeroColunas = map(int, input().split())
linhas = [0] * numeroLinhas
colunas = [0] * numeroColunas
for l in range(0, numeroLinhas):
	linha = list(map(int, input().split()))
	for c in range(0, numeroColunas):
		linhas[l] += linha[c]
		colunas[c] += linha[c]
print(sorted(linhas + colunas, reverse=True)[0])
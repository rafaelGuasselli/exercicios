tamanho = 3
matriz = []
linhas = [0] * tamanho
colunas = [0] * tamanho
original = -1
for l in range(0, tamanho):
	linha = list(map(int, input().split()))
	matriz.append(linha)
	ehAOriginal = True
	for c in range(0, tamanho):
		if linha[c] == 0:
			ehAOriginal = False
		linhas[l] += linha[c]
		colunas[c] += linha[c]
	if ehAOriginal:
		original = linha[l]

tamanho = int(input())
matriz = []
linhas = [0] * tamanho
colunas = [0] * tamanho
for l in range(0, tamanho):
	linha = list(map(int, input().split()))
	matriz.append(linha)
	for c in range(0, tamanho):
		linhas[l] += linha[c]
		colunas[c] += linha[c]

somaOriginal = linhas[0] if linhas[0] == linhas[1] else linhas[2]
somaAdulterada = 0
linha = 0
coluna = 0
for i in range(0, tamanho):
	if linhas[i] != somaOriginal:
		somaAdulterada = linhas[i]
		linha = i
	if colunas[i] != somaOriginal:
		coluna = i

diferenca = somaAdulterada - somaOriginal
numeroAdulterado = matriz[linha][coluna]
numeroOriginal = numeroAdulterado - diferenca
print("{:n} {:n}".format(numeroOriginal, numeroAdulterado))
qtdPalavras, qtdDescricoes = map(int, input().split())

dicionario = {}
for i in range(0, qtdPalavras):
	palavra, valor = input().split()
	valor = int(valor)
	dicionario[palavra] = valor

total = 0
while qtdDescricoes > 0:
	frase = input().split(" ")
	for palavra in frase:
		total += dicionario[palavra] if palavra in dicionario else 0

	if "." in frase:
		print(total)
		total = 0
		qtdDescricoes -= 1
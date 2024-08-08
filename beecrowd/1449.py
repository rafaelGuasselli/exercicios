def ex():
	qtdPalavrasDic, qtdLinhasLetra = map(int, input().split())
	dicionario = {}
	for i in range(0, qtdPalavrasDic):
		palavra = input()
		traducao = input()
		dicionario[palavra] = traducao

	for i in range(0, qtdLinhasLetra):
		linha = input().split()
		traducao = ""
		for palavra in linha:
			traducao += dicionario[palavra] if palavra in dicionario else palavra
			traducao += " "
		print(traducao.strip())

numCasosTeste = int(input())
for i in range(0, numCasosTeste):
	ex()
	print()
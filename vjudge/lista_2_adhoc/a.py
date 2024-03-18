def id(palavra):
	palavra = palavra.rstrip(" ")
	palavra = list(palavra)

	palavra.sort()
	palavra = "".join(palavra)

	return hash(palavra)

def ex():
	qtdLinhas, qtdColunas = map(int, input().split())
	matrix = []
	celulasEspeciais = [[] for i in range(qtdLinhas)]
	linhas = ""
	colunas = ""
	diagonais1 = ""
	diagonais2 = ""

	for i in range(qtdLinhas):
		linha = input()
		matrix.append(linha)
		linhas += linha
	
	for c in range(qtdColunas):
		for l in range(qtdLinhas):
			colunas += matrix[l][c]
	
	for i in range()


	qtdAnagramas = int(input())
	anagramas = []
	
	for i in range(qtdAnagramas):
		anagrama = input()
		anagramas.append(anagrama)

	


	print(count)

ex()
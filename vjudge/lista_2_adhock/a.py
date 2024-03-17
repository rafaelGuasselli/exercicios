def id(palavra):
	palavra = palavra.rstrip(" ")
	palavra = list(palavra)

	palavra.sort()
	palavra = "".join(palavra)

	return hash(palavra)

def ex():
	qtdLinhas, qtdColunas = map(int, input().split())
	matrix = []

	for i in range(qtdLinhas):
		linha = input()
		matrix.append(linha)

	qtdAnagramas = int(input())
	anagramas = []
	
	for i in range(qtdAnagramas):
		anagrama = input()
		anagramas.append(anagrama)

	count = 0
	for anagrama in anagramas:
		idAnagrama = id(anagrama)
		for l in range(qtdLinhas):
			for c in range(qtdColunas - (len(anagrama) - 1)):
				palavra = matrix[l][:c]
				if id(palavra) == idAnagrama:
					count += 1
	print(count)

ex()
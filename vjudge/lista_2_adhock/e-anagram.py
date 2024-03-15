def id(palavra):
	palavra = ''.join(x for x in palavra if x != " ")
	palavra = list(palavra)

	palavra.sort()
	palavra = "".join(palavra)
	return hash(palavra)

def combinacoes(grupo):
	length = len(grupo)
	combinacoes = []
	
	grupo.sort()	
	for i in range(0, length):
		for j in range(i+1, length):
			combinacoes.append("{:s} = {:s}".format(grupo[i], grupo[j]))

	combinacoes.sort()
	return combinacoes

def acharAnagramas(entrada):
	anagramas = {}
	for palavra in entrada:
		idAnagrama = id(palavra)
		if not idAnagrama in anagramas:
			anagramas[idAnagrama] = []
		anagramas[idAnagrama].append(palavra)

	equivalencias = []
	for key in anagramas:
		grupo = anagramas[key]
		equivalencias.extend(combinacoes(grupo))
	equivalencias.sort()

	for equivalencia in equivalencias:
		print(equivalencia)
	

def ex():
	palavras = []
	while True:
		try:
			entrada = input()
			if len(entrada) > 0:
				palavras.append(entrada)
			else:
				break
		except:
			break
	return acharAnagramas(palavras)

qtdTestes = int(input())
breakLine = False
input()
for i in range(qtdTestes):
	if breakLine:
		print()
	breakLine = True
	ex()
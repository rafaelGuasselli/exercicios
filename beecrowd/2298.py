def ehSequencia(cartas):
	cartas.sort()
	for i in range(0, len(cartas)-1):
		if cartas[i+1] != cartas[i] + 1:
			return False
	return 200 + cartas[0]

def cartasIguais(cartas):
	index = {}
	frequencias = []

	for i in range(0, len(cartas)):
		carta = cartas[i]
		if carta not in index:
			frequencias.append([1, carta])
			index[carta] = len(frequencias) - 1
		else:
			frequencias[index[carta]][0] += 1

	frequencias.sort(reverse=True)
	cartaMaisFrequente = frequencias[0][1]
	segundaCartaMaisFrequente = frequencias[1][1]

	maiorFrequencia = frequencias[0][0]
	segundaMaiorFrequencia = frequencias[1][0]

	if maiorFrequencia == 4:
		return 180 + cartaMaisFrequente
	elif maiorFrequencia == 3 and segundaMaiorFrequencia == 2:
		return 160 + cartaMaisFrequente
	elif maiorFrequencia == 3:
		return 140 + cartaMaisFrequente
	elif maiorFrequencia == 2 and segundaMaiorFrequencia == 2:
		return 3 * cartaMaisFrequente + 2 * segundaCartaMaisFrequente + 20
	elif maiorFrequencia == 2:
		return cartaMaisFrequente
	else:
		return 0


def ex():
	cartas = list(map(int, input().split()))
	total = ehSequencia(cartas)

	if total:
		print(total)
	else:
		print(cartasIguais(cartas))

qtdTestes = int(input())
for i in range(qtdTestes):
	print("Teste {:n}".format(i+1))
	ex()
	print()
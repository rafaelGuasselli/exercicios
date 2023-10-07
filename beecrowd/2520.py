def ex(entrada):
	numeroLinhas, numeroColunas = map(int, entrada.split())
	posPikachu = (False, -1)
	posAshe = (False, -1)

	for i in range(0, numeroLinhas):
		linha = list(map(int, input().split()))
		if 1 in linha:
			posAshe = (i, linha.index(1))
		if 2 in linha:
			posPikachu = (i,  linha.index(2))

	distancia = abs(posPikachu[0] - posAshe[0]) + abs(posPikachu[1] - posAshe[1])
	print(distancia)

while True:
	try:
		entrada = input()
		ex(entrada)
	except EOFError:
		break
def ex(entrada):
	qtdAtacantes, qtdDefensores = map(int, entrada.split())

	distanciaAtacantes = list(map(int, input().split()))
	distanciaDefensores = list(map(int, input().split()))

	distanciaAtacantes.sort()
	distanciaDefensores.sort()
	impedido = distanciaAtacantes[0] < distanciaDefensores[1]
	print("Y" if impedido else "N")


while True:
	try:
		entrada = input()
		ex(entrada)
	except EOFError:
		break
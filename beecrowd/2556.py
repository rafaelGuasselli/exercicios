def ex(entrada):
	qtdAnotados = int(entrada)
	minutos = list(map(int, input().split()))
	minutos.sort()

	maxLotacao = int(qtdAnotados/2)
	maxTempo = minutos[maxLotacao] - minutos[maxLotacao - 1]

	print("{:n} {:n}".format(maxLotacao, maxTempo))

while True:
	try:
		ex(input())
	except:
		break
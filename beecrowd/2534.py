def ex(entrada):
	qtdNotas, qtdConsultas = map(int, entrada.split())
	
	notas = []
	for i in range(qtdNotas):
		nota = int(input())
		notas.append(nota)

	notas.sort(reverse=True)
	for i in range(qtdConsultas):
		posicaoNota = int(input())
		print(notas[posicaoNota-1])


while True:
	try:
		entrada = input()
		ex(entrada)
	except EOFError:
		break
def ex(entradas):
	qtdJogadores, qtdQuadrados = map(int, entradas.split())
	armadilhas = list(map(int, input().split()))
	totalRodadas = int(input())

	penalidade = [False] * qtdJogadores
	posicao = [0] * qtdJogadores
	jogadorAtual = 0
	ganhador = -1

	for i in range(0, totalRodadas):
		dado1, dado2 = map(int, input().split())
		total = dado1 + dado2


		while penalidade[jogadorAtual]:
			penalidade[jogadorAtual] = False
			jogadorAtual = (jogadorAtual + 1) % qtdJogadores
		
		posicao[jogadorAtual] += total
		if posicao[jogadorAtual] in armadilhas:
			penalidade[jogadorAtual] = True

		if posicao[jogadorAtual] > qtdQuadrados and ganhador == -1:
			ganhador = jogadorAtual
		
		jogadorAtual = (jogadorAtual + 1) % qtdJogadores
	print(ganhador + 1)

while True:
	entrada = input()
	if entrada == "0 0":
		break
	ex(entrada)
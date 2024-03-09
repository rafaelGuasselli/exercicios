def procurarCartaNosMontes(carta, montes):
	for i in range(len(montes)):
		monte = montes[i]
		if len(monte) > 0 and carta == monte[-1]:
			return i
	return -1

def ex(entrada):
	qtdCartas, qtdJogadores = map(int, entrada.split())
	pilhaDeCompra = list(map(int, input().split()))
	montes = [[] for i in range(qtdJogadores)]
	descarte = []
	jogadorAtual = 0

	for cartaDaVez in pilhaDeCompra:
		cartaNoMonteM = procurarCartaNosMontes(cartaDaVez, montes)
		if cartaDaVez in descarte:
			descarte.remove(cartaDaVez)
			montes[jogadorAtual].append(cartaDaVez)
			montes[jogadorAtual].append(cartaDaVez)
		elif cartaNoMonteM != -1:
			monteRoubado = montes[cartaNoMonteM]
			montes[cartaNoMonteM] = []
			montes[jogadorAtual].extend(monteRoubado)
			montes[jogadorAtual].append(cartaDaVez)
		else:
			descarte.append(cartaDaVez)
			jogadorAtual = (jogadorAtual + 1) % qtdJogadores
	
	maiorMonte = len(max(montes, key=len)) if len(montes) > 1 else len(montes[0])
	ganhadores = []
	saida = str(maiorMonte) + " "

	for i in range(qtdJogadores):
		if len(montes[i]) == maiorMonte:
			saida += str(i+1) + " "
	
	print(saida.strip())



while True:
	entrada = input()
	if entrada == "0 0":
		break
	ex(entrada)
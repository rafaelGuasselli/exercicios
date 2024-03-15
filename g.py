import io,os, sys

def fastInput():
	letInput = sys.stdin.readline
	return letInput().rstrip("\r\n") #decode().rstrip("\r\n")

def winAvg(w, l):
	if (w+l) == 0: 
		return "-"
	return w/(w + l)

def definirGanhador(jogada1, jogada2):
	dicionario = {
		"rockrock": 0,
		"rockpaper": -1,
		"rockscissors": 1,
		"scissorsrock": -1,
		"scissorspaper": 1,
		"scissorsscissors": 0,
		"paperrock": 1,
		"paperpaper": 0,
		"paperscissors": -1
	}

	return dicionario[jogada1+jogada2]

def ex(entrada):
	qtdJogadores, qtdJogos = map(int, entrada.split())
	totalJogos = int(qtdJogadores * qtdJogos * (qtdJogadores-1)/2)
	
	vitorias = [0] * qtdJogadores
	derrotas = [0] * qtdJogadores

	for i in range(totalJogos):
		entrada = fastInput()
		jogador1, jogada1, jogador2, jogada2 = entrada.split()
		resultado = definirGanhador(jogada1, jogada2)
		jogador1 = int(jogador1)-1
		jogador2 = int(jogador2)-1
		

		if resultado == 1:
			vitorias[jogador1] += 1
			derrotas[jogador2] += 1
		elif resultado == -1:
			vitorias[jogador2] += 1
			derrotas[jogador1] += 1
	
	for i in range(qtdJogadores):
		media = winAvg(vitorias[i], derrotas[i])
		if not media == "-":
			print("{:.3f}".format(media))
		else:
			print("-")



breakline = False
while True:
	entrada = fastInput()
	if entrada == "0":
		break
	if breakline:
		print()
	ex(entrada)
	breakline = True
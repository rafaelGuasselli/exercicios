import io, os, sys

def print(message, end):
	sys.stdout.write(str(message) + str(end))

def printMat(move, matriz, qtdLinhas, qtdColunas):
	my, mx = move
	for y in range(qtdLinhas):
		for x in range(qtdColunas):
			py = (y - my) % qtdLinhas
			px = (x - mx) % qtdColunas

			print(matriz[py][px], " " if x != qtdColunas-1 else "")
		print("", "\n")
	
	
def ex(entrada):
	qtdLinhas, qtdColunas = map(int, entrada.split())
	matriz = []
	
	for y in range(qtdLinhas):
		linha = list(map(int, input().split()))
		matriz.append(linha)

	move = [0, 0]
	while True:
		entrada = input()
		if entrada == "0 0":
			break
		
		mx, my = map(int, entrada.split())
		move[0] -= my
		move[1] += mx
	printMat(move, matriz, qtdLinhas, qtdColunas)


numeroTeste = 1
while True:
	entrada = input()
	if entrada == "0 0":
		break

	print("Teste {:n}".format(numeroTeste), "\n")
	ex(entrada)
	print("", "\n")

	numeroTeste += 1



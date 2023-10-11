def ex(entrada):
	numeroLinhas, numeroColunas, pos = map(int, entrada.split())
	ventiladores = []
	pos -= 1
	for l in range(0, numeroLinhas):
		linha = list(map(int, input().split()))
		ventiladores.append(linha)
		ventilador = 0
		for c in range(0, numeroColunas):
			ventiladores[l][c] = [ventiladores[l][c], ventiladores[l][c] > 0]
			if ventiladores[l][c][1]:
				ventilador = ventiladores[l][c][0]
			else:
				ventiladores[l][c][0] += ventilador
		for c in reversed(range(0, numeroColunas)):
			if ventiladores[l][c][1]:
				ventilador = ventiladores[l][c][0]
			else:
				ventiladores[l][c][0] -= ventilador

	for i in range(0, numeroLinhas):
		pos += ventiladores[i][pos][0]
		if ventiladores[i][pos][1]:
			print("BOOM {:n} {:n}".format(i + 1, pos + 1))
			return
	print("OUT {:n}".format(pos + 1))
while True:
	entrada = input()
	if entrada == "0 0 0":
		break
	ex(entrada)
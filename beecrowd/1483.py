from math import ceil

def calcularDigitosIguais(n, m):
	qtdIgual = 0
	rn = n[::-1]
	rm = m[::-1]
	for i in range(0, 4):
		if rn[i] != rm[i]:
			break
		qtdIgual += 1
	return qtdIgual

def calcularMesmoGrupo(n, m):
	qtd = 0
	nn = int(n[-2] + n[-1])
	mn = int(m[-2] + m[-1])
	return ceil(nn/4) == ceil(mn/4)

def ex(entrada):
	valor, n, m = entrada.split()
	valor = float(valor)
	n = n.zfill(4)
	m = m.zfill(4)
	qtdIguais = calcularDigitosIguais(n, m)
	premio = {
		2: 50,
		3: 500,
		4: 3000
	}

	if qtdIguais >= 2:
		print("{:.2f}".format(premio[qtdIguais] * valor))
	elif calcularMesmoGrupo(n, m): 
		print("{:.2f}".format(16 * valor))
	else:
		print("0.00")

while True:
	entrada = input()
	if entrada == "0 0 0":
		break
	ex(entrada)
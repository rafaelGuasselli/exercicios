def algoritmo(cartas):
	cartasNaMao = cartas[27:]
	cartas = cartas[:27]
	y = 0
	
	for i in range(0, 3):
		carta = cartas[-1]
		x = 10 if not carta[0].isnumeric() else int(carta[0])
		y += x
		qtdRemover = 10 - x
  
		cartas.pop()
		cartas = cartas[:len(cartas)-qtdRemover]
	return (cartas + cartasNaMao)[y-1]

proximasCartas = []
def pegarCartas():
	global proximasCartas
	cartas = proximasCartas

	while len(cartas) < 52:
		entrada = input().split()
  
		if len(entrada) + len(cartas) > 52:
			qtd = len(entrada) + len(cartas) - 52
			proximasCartas = entrada[len(entrada)-qtd:]
			entrada = entrada[:len(entrada)-qtd]
		else:
			cartas.extend(entrada)
			proximasCartas = []
	return cartas

def ex():
	return algoritmo(pegarCartas())

qtdTestes = int(input())
for i in range(qtdTestes):
	saida = ex()
	print("Case {:n}: {:s}".format(i+1, saida))
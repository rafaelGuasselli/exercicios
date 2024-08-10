def ex(entrada):
	qtdAtributos = int(entrada)
	qtdCartasMarcos, qtdCartasLeonardo = map(int, input().split())

	cartasMarcos = []
	cartasLeonardo = []

	for i in range(0, qtdCartasMarcos):
		atributos = list(map(int, input().split()))
		cartasMarcos.append(atributos)
	
	for i in range(0, qtdCartasLeonardo):
		atributos = list(map(int, input().split()))
		cartasLeonardo.append(atributos)
	
	indexCartaMarco, indexCartaLeonardo = map(int, input().split())
	atributoSorteado = int(input()) - 1

	forcaCartaMarco = cartasMarcos[indexCartaMarco - 1][atributoSorteado]
	forcaCartaLeonardo = cartasLeonardo[indexCartaLeonardo - 1][atributoSorteado]

	if forcaCartaMarco > forcaCartaLeonardo:
		print("Marcos")
	elif forcaCartaMarco < forcaCartaLeonardo:
		print("Leonardo")
	else:
		print("Empate")


while True:
	try:
		entrada = input()
		ex(entrada)
	except:
		break
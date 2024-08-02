from math import radians, sin, cos

def ex(entrada):
	alturaArqueiro, distancia, angulo = map(float, entrada.split())
	angulo = radians(angulo)

	hipotenusa = distancia/sin(angulo)
	diferencaNaAltura = cos(angulo) * hipotenusa
	alturaCoelho = alturaArqueiro - diferencaNaAltura
	print("{:.4f}".format(alturaCoelho))

while True:
	try:
		entrada = input()
		ex(entrada)
	except EOFError:
		break
distanciaPercorridaEmKM = 0
ultimoTempoEmSegundos = 0
velocidadeAtualEmKMPH = 0


def converterStringParaSegundos(string):
	horas, minutos, segundos = string.split(":")
	return int(segundos) + int(minutos) * 60 + int(horas) * 3600


def ex(entrada):
	global distanciaPercorridaEmKM
	global ultimoTempoEmSegundos
	global velocidadeAtualEmKMPH
	entradas = entrada.split(" ")

	if len(entradas) == 1:
		tempo = entradas[0]
		tempoAtualEmSegundos = converterStringParaSegundos(tempo)
		diferencaDeTempo = tempoAtualEmSegundos - ultimoTempoEmSegundos
		distanciaPercorridaEmKM += velocidadeAtualEmKMPH * diferencaDeTempo/3600

		ultimoTempoEmSegundos = tempoAtualEmSegundos
		print("{:s} {:.2f} km".format(tempo, distanciaPercorridaEmKM))

	else:
		tempo, velocidade = entradas
		tempoAtualEmSegundos = converterStringParaSegundos(tempo)
		diferencaDeTempo = tempoAtualEmSegundos - ultimoTempoEmSegundos
		distanciaPercorridaEmKM += velocidadeAtualEmKMPH * diferencaDeTempo/3600

		ultimoTempoEmSegundos = tempoAtualEmSegundos
		velocidadeAtualEmKMPH = float(velocidade)


while True:
	try:
		entrada = input()
		ex(entrada)
	except:
		break
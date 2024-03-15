def ex(entrada):
	ANGULO_POR_HORA = 30
	ANGULO_POR_MINUTO = 6
	ANGULO_POR_MINUTO_HORA = 0.5
	horas, minutos = map(int, entrada.split(":"))

	anguloHora = horas * ANGULO_POR_HORA + minutos * ANGULO_POR_MINUTO_HORA
	anguloMinutos = minutos * ANGULO_POR_MINUTO

	anguloEntre = abs(anguloHora-anguloMinutos)
	anguloEntreInverso = 360 - anguloEntre

	print("{:.3f}".format(min(anguloEntreInverso, anguloEntre)))


while True:
	entrada = input()
	if entrada == "0:00":
		break
	ex(entrada)
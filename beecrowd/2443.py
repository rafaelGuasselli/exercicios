def mdc(a, b):
	a, b = max(a, b), min(a, b)
	if b == 0:
		return a
	else:
		return mdc(b, a % b)

def mmc(a, b):
	divisor = mdc(a, b)
	return (a * b)/divisor

numerador1, divisor1, numerador2, divisor2 = map(int, input().split())

#Faz o mmc pra achar o divisor da nova fração
divisorResultado = mmc(divisor1, divisor2)

#Acha quantas vezes o numerador1 e 2 cabe na nova fração
numeradorResultado1 = (divisorResultado/divisor1) * numerador1
numeradorResultado2 = (divisorResultado/divisor2) * numerador2
numeradorResultado = numeradorResultado1 + numeradorResultado2

#Acha o maior divisor comum para dividir o numerador e o divisor, assim simplificando a fração.
simplificador = mdc(numeradorResultado, divisorResultado)
numeradorResultado /= simplificador
divisorResultado /= simplificador

print("{:n} {:n}".format(numeradorResultado, divisorResultado))
from functools import cmp_to_key

def mod(a, m):
	ma = a % m
	if a < 0 and ma > 0:
		ma -= m
	return ma

def ordenar(a, b, m):
	ma = mod(a, m)
	mb = mod(b, m)

	if ma != mb:
		return ma - mb
	else:
		doisImpares = a % 2 == 1 and b % 2 == 1
		doisPares = a % 2 == 0 and b % 2 == 0
		
		if doisPares:
			return a - b
		
		if doisImpares:
			return b - a

		return (b % 2) - (a % 2)

def ex(entrada):
	qtdNumeros, m = map(int, entrada.split())
	numeros = []
	for i in range(0, qtdNumeros):
		numero = int(input())
		numeros.append(numero)

	numeros.sort(key=cmp_to_key(lambda a, b: ordenar(a, b, m)))
	print("{:n} {:n}".format(qtdNumeros, m))
	for num in numeros:
		print(num)



while True:
	entrada = input()
	if entrada == "0 0":
		print("0 0")
		break
	ex(entrada)
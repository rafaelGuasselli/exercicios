def ex(entrada):
	n = int(entrada)
	resultado = "1" * n
	print(int(resultado, 2))

contador = 1
while True:
	entrada = input()
	if entrada == "0":
		break

	print("Teste {:n}".format(contador))
	ex(entrada)
	print()
	contador += 1
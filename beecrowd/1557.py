def ex(entrada):
	tamanho = int(entrada)
	qtdDigitos = len(str(2 ** ((tamanho - 1) * 2)))

	for l in range(0, tamanho):
		for c in range(0, tamanho):
			valor = 2 ** (l + c)
			print("{:{:n}d}".format(valor, qtdDigitos), end=" " if c < tamanho - 1 else "")
		print()

while True:
	entrada = input()
	if entrada == "0":
		break
	ex(entrada)
	print()
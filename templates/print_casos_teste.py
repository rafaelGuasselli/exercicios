def ex(entrada):
	print()

casoDeTesteNum = 1
while True:
	entrada = input()
	if entrada == "0":
		break
	print("Teste {:n}:".format(casoDeTesteNum))
	ex(entrada)
	casoDeTesteNum += 1
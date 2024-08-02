def ex(entrada):
	count = 0
	frequencias = {}
	ordem = []

	entrada.append("")
	for arvore in entrada:
		if not arvore:
			ordem.sort()
			for arvere in ordem:
				print("{:s} {:.4f}".format(arvere, 100 * frequencias[arvere]/count))
			print()
			ordem.clear()
			frequencias.clear()
			count = 0
			continue

		if not arvore in ordem:
			ordem.append(arvore)
			frequencias[arvore] = 1
		else:
			frequencias[arvore] += 1
		count += 1
		 

inputArray = []
qtdTestes = int(input())
while True:
	try:
		entrada = input()
		inputArray.append(entrada)
	except EOFError:
		ex(inputArray)
		break

qtdPaises = int(input())

medalhasPorPais = []
for i in range(0, qtdPaises):
	nomePais, qtdOuros, qtdPratas, qtdBronzes = input().split()
	qtdOuros, qtdPratas, qtdBronzes = map(int, [qtdOuros, qtdPratas, qtdBronzes])
	medalhasPorPais.append((-qtdOuros, -qtdPratas, -qtdBronzes, nomePais))

medalhasPorPais.sort()
for pais in medalhasPorPais:
	ouros, prata, bronzes, nome = pais
	print("{:s} {:n} {:n} {:n}".format(nome, -ouros, -prata, -bronzes))
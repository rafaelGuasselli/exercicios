qtdPaises = int(input())

medalhasPorPais = []
for i in range(0, qtdPaises):
	nome, ouros, pratas, bronzes = input().split()
	ouros, pratas, bronzes = map(int, [ouros, pratas, bronzes])
	medalhasPorPais.append((-qtdOuros, -qtdPratas, -qtdBronzes, nome))

medalhasPorPais.sort()
for pais in medalhasPorPais:
	ouros, pratas, bronzes, nome = pais
	print("{:s} {:n} {:n} {:n}".format(nome, -ouros, -prata, -bronzes))
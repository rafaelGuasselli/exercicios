def ex2227(numeroDeAeroportos, numeroVoos):
	totalVoos = [0] * numeroDeAeroportos
	maiorQtdVoos = 0

	for i in range(0, numeroVoos):
		saida, chegada = map(int, input().split())
		totalVoos[saida - 1] += 1
		totalVoos[chegada - 1] += 1
		
		maior = max(totalVoos[saida - 1], totalVoos[chegada - 1])
		maiorQtdVoos = max(maiorQtdVoos, maior)

	for i in range(0, numeroDeAeroportos):
		if totalVoos[i] == maiorQtdVoos:
			print(i+1, end=" ")
	print()

entrada = input()
numeroDoTeste = 1
while entrada != "0 0":
	numeroDeAeroportos, numeroVoos = map(int, entrada.split())
	print("Teste {:n}".format(numeroDoTeste))
	ex2227(numeroDeAeroportos, numeroVoos)
	print()
	numeroDoTeste += 1
	entrada = input()
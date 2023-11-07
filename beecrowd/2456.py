def checar(linha):
	crescente = False
	decrescente = False
	for i in range(1, len(linha)):
		if linha[i] > linha[i-1]:
			crescente = True

		if linha[i] < linha[i-1]:
			decrescente = True
	if crescente == decrescente:
		print("N")
	elif crescente:
		print("C")
	else:
		print("D")

linha = list(map(int, input().split()))
checar(linha)
def ex(entrada):
	qtdAlunos = int(entrada)
	notas = []

	for i in range(0, qtdAlunos):
		nome, nota = input().split()
		notas.append((-int(nota), nome))
	notas.sort()
	print(notas[-1][1])

instancia = 1
while True:
	try:
		entrada = input()
		print("Instancia {:n}".format(instancia))
		instancia += 1
		ex(entrada)
		print()
	except EOFError:
		break	
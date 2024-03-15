def ex(entrada):
	qtdLivros = int(entrada)
	livros = []

	for i in range(0, qtdLivros):
		livro = input()
		livros.append(livro)
	livros.sort()
	for livro in livros:
		print(livro)

while True:
	try:
		entrada = input()
		ex(entrada)
	except EOFError:
		break
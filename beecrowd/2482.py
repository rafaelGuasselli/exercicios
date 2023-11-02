qtdLinguas = int(input())
linguas = {}
for i in range(0, qtdLinguas):
	lingua = input()
	traducao = input()
	linguas[lingua] = traducao

qtdEtiquetas = int(input())
for i in range(0, qtdEtiquetas):
	nome = input()
	lingua = input()
	print(nome)
	print(linguas[lingua])
	print()
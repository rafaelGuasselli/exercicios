qtdNomes = int(input())
listas = {}

for i in range(qtdNomes):
	nome = input()
	if not len(nome) in listas:
		listas[len(nome)] = []
	listas[len(nome)].append(nome)

while len(listas) > 0:
	iterator = sorted(listas)
	for key in iterator:
		lista = listas[key]
		nome = lista.pop(0)
		print(nome, end=", " if lista != listas[iterator[-1]] else "\n")
		if len(lista) == 0:
			del listas[key]
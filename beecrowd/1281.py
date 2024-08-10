def ex():
	qtdProdFeira = int(input())
	precos = {}

	for i in range(0, qtdProdFeira):
		nome, preco = input().split()
		precos[nome] = float(preco)
	
	qtdProdDona = int(input())
	precoTotal = 0
	for i in range(0, qtdProdDona):
		nome, qtd = input().split()
		precoTotal += precos[nome] * int(qtd)
	print("R$ {:.2f}".format(precoTotal))
	

numIdas = int(input())
for i in range(0, numIdas):
	ex()
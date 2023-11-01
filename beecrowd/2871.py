from functools import reduce
def ex(entrada):
	qtdLinha, qtdColuna = map(int, entrada.split())
	total = 0
	#Soma todos os valores da matriz
	for i in range(0, qtdLinha):
		linha = list(map(int, input().split()))
		total += reduce(lambda p, c: p + c, linha)
	
	#Acha a qtd sacas e litros
	sacas = total // 60
	litros = total - (sacas * 60)
	print("{:n} saca(s) e {:n} litro(s)".format(sacas, litros))


while True:
	try:
		entrada = input()
		ex(entrada)
	except EOFError:
		break
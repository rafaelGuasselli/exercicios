def ex(entrada):
	qtd = int(entrada)
	funcao = {}
	invertido = {}
	val = 2
	message = ["Not a function.", "Not invertible.", "Invertible."]

	for i in range(0, qtd):
		variavel, valor = input().split(" -> ")
		if variavel in funcao and funcao[variavel] != valor:
			val = min(val, 0)
		if valor in invertido and invertido[valor] != variavel:
			val = min(val, 1)
		funcao[variavel] = valor
		invertido[valor] = variavel
	print(message[val])


while True:
	entrada = input()
	if entrada == "0":
		break
	ex(entrada)
def ex(qtdVagoes, entrada, saida):
	stack = []
	prox = saida.pop(0)
	array = []

	for i in entrada:
		stack.append(i)
		array.append("I")
		while len(stack) > 0 and stack[-1] == prox:
			stack.pop()
			array.append("R")
			if len(saida) > 0:
				prox = saida.pop(0)

	for i in array:
		print(i, end="")
	
	if len(stack) > 0:
		print(" Impossible", end="")
	print()


while True:
	n = int(input())
	
	if n == 0:
		break
	
	entrada = list(input().split())
	saida = list(input().split())
	ex(n, entrada, saida)
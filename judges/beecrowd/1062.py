def ex(qtdVagoes, entrada):
	ordem = list(map(int, entrada.split()))
	stack = []
	prox = ordem.pop(0)

	for i in range(1, qtdVagoes + 1):
		stack.append(i)
		while len(stack) > 0 and stack[-1] == prox:
			stack.pop()
			if len(ordem) > 0:
				prox = ordem.pop(0)
	print("Yes" if len(stack) == 0 else "No")

def exInput(entrada):
	qtdVagoes = int(entrada)
	while True:
		entrada = input()
		if entrada == "0":
			break
		ex(qtdVagoes, entrada)
	print()


while True:
	entrada = input()
	if entrada == "0":
		break
	exInput(entrada)
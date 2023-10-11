def ex(entrada):
	tamanho = int(entrada)
	meioPos = tamanho // 2
	quadradoPos = tamanho // 3

	for l in range(0, tamanho):
		for c in range(0, tamanho):
			if l == c and c == meioPos:
				print("4", end="")
			elif l >= quadradoPos and l < (tamanho-quadradoPos) and c >= quadradoPos and c < (tamanho-quadradoPos):
				print("1", end="")
			elif l == c:
				print("2", end="")
			elif l == (tamanho - c - 1) or c == (tamanho - l - 1):
				print("3", end="")
			else:
				print("0", end="")
		print()

while True:
	try:
		entrada = input()
		ex(entrada)
		print()
	except EOFError:
		break
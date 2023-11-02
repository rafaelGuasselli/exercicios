def ex(entrada):
	tamanhoMatrix = int(entrada)

	for l in range(0, tamanhoMatrix):
		for c in range(0, tamanhoMatrix):
			#2 Caso seja da diagonal secundaria
			if l == (tamanhoMatrix - c - 1) or c == (tamanhoMatrix - l - 1):
				print("2", end="")
			elif l == c:
			#1 Caso seja da diagonal principal
				print("1", end="")
			else:
			#3 Caso nenhum dos dois
				print("3", end="")
		print()

while True:
	try:
		entrada = input()
		ex(entrada)
	except EOFError:
		break
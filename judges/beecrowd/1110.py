from collections import deque

while True:
	qtd_cartas = int(input().strip())
	if qtd_cartas == 0:
		break

	cartas = deque(range(1, qtd_cartas + 1))
	descartadas = []

	while len(cartas) >= 2:
		descartadas.append(cartas.popleft())
		cartas.append(cartas.popleft())

	print("Discarded cards:", end="")
	if descartadas:
		print(" " + ", ".join(map(str, descartadas)))
	else:
		print()

	print("Remaining card:", cartas[0])


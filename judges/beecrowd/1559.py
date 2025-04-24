#TODO: Simplificar esse código
def ex():
	matriz = []
	fim = False
	for i in range(0, 4):
		linha = list(map(int, input().split()))
		matriz.append(linha)

		if 2048 in linha:
			fim = True

	up = False
	left = False
	down = False
	right = False
	

	for y in range(4):
		lastElement = None
		for x in range(4):
			if lastElement and matriz[y][x] == 0:
				right = True

			if matriz[y][x] == 0:
				continue

			if matriz[y][x] != lastElement:
				lastElement = matriz[y][x]
			else:
				right = True

	for x in range(4):
		lastElement = None
		for y in range(4):
			if lastElement and matriz[y][x] == 0:
				down = True

			if matriz[y][x] == 0:
				continue

			if matriz[y][x] != lastElement:
				lastElement = matriz[y][x]
			else:
				down = True
	
	for y in range(4):
		lastElement = None
		for x in range(4):
			if lastElement and matriz[y][3-x] == 0:
				left = True
			
			if matriz[y][3-x] == 0:
				continue

			if matriz[y][3-x] != lastElement:
				lastElement = matriz[y][3-x]
			else:
				left = True

	for x in range(4):
		lastElement = None
		for y in range(4):
			if lastElement and matriz[3-y][x] == 0:
				up = True
			
			if matriz[3-y][x] == 0:
				continue

			if matriz[3-y][x] != lastElement:
				lastElement = matriz[3-y][x]
			else:
				up = True

	result = ""

	if down:
		result += "DOWN "

	if left:
		result += "LEFT "

	if right:
		result += "RIGHT "

	if up:
		result += "UP "

	if (not down and not right and not left and not up) or fim:
		result = "NONE "
	
	print(result[:-1])



qtdTestes = int(input())
for i in range(qtdTestes):
	ex()
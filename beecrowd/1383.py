def testarMatriz(matriz):
	for l in range(0, 9):
		testeLinha = [0] * 10
		testeColuna = [0] * 10
		testeQuadrado = [0] * 10
		for c in range(0, 9):
			if testeLinha[matriz[l][c]]:
				return False
			if testeColuna[matriz[c][l]]:
				return False
			if testeQuadrado[matriz[((l // 3) * 3) + (c // 3)][((l % 3) * 3) + (c % 3)]]:
				return False
			testeLinha[matriz[l][c]] = 1
			testeColuna[matriz[c][l]] = 1
			testeQuadrado[matriz[((l // 3) * 3) + (c // 3)][((l % 3) * 3) + (c % 3)]] = 1
	return True

def ex():
	matriz = []
	
	for l in range(0, 9):
		linha = list(map(int, input().split()))
		matriz.append(linha)
	
	print("SIM" if testarMatriz(matriz) else "NAO")


numeroDeTestes = int(input())
for i in range(0, numeroDeTestes):
	print("Instancia {:n}".format(i + 1))
	ex()
	print()
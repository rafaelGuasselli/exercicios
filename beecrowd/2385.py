def calcM(linha, coluna, X, Y, Z):
	return (linha * X + coluna * Y) % Z

tamanho = int(input())
P, Q, R, S, X, Y = map(int, input().split())
linha, coluna = map(int, input().split())

valor = 0
for i in range(1, tamanho+1):
	valA = calcM(linha, i, P, Q, X)
	valB = calcM(i, coluna, R, S, Y)
	valor += valA * valB
print(valor)
n, m = map(int, input().split())

total = 0
matrix = []

for i in range(n):
	lista = list(map(int, input().split()))
	matrix.append(lista)

for i in range(m):
	maior = 0
	for j in range(n):
		maior = max(maior, matrix[j][i])
	total += maior
print(total)
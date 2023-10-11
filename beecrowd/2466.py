numeroBolasNaPrimeiraFileira = int(input())
fileiras = []
fileiras.append(list(map(int, input().split()))) #primeira fileira

for i in range(1, numeroBolasNaPrimeiraFileira):
	fileiras.append([])
	for j in range(0, numeroBolasNaPrimeiraFileira - i):
		preta = fileiras[i-1][j] == fileiras[i-1][j+1]
		fileiras[i].append(1 if preta else 0)
print("preta" if fileiras[numeroBolasNaPrimeiraFileira-1][0] == 1 else "branca")
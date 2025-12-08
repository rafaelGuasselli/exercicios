t=int(input())
while t:
	t-=1
	n=int(input())
	maximo = 0

	for i in range(n):
		for j in range(n):
			atual = i*n+j+1

			soma = atual
			if j < n-1:
				soma += atual+1
			if j > 0:
				soma += atual-1
			if i > 0:
				soma += atual-n
			if i < n-1:
				soma += atual+n

			maximo = max(maximo, soma)
	print(maximo)	
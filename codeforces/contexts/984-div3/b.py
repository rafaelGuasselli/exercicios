t = int(input())

while True:
	if t == 0:
		break
	t -= 1

	n, k = map(int, input().split())
	marcas = [0] * k

	for i in range(0, k):
		b, c = map(int, input().split())
		marcas[b-1] += c
	
	marcas.sort()
	soma = 0
	for i in range(0, min(n, k)):
		soma += marcas[k-i-1]

	print(soma)

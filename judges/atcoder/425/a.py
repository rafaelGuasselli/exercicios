n = int(input())

soma = 0
for i in range(1, n+1):
	soma += (pow(-1, i)) * i * i * i
print(soma)

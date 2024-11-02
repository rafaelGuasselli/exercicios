n = int(input())
lista = list(map(int, input().split()))
target = sum(lista) // 2

dp = [0] * 10010
for i in range(n): 
	if lista[i] > target: continue
	for k in range(target, 0, -1):
		if dp[k] != 0 and (k + lista[i]) <= target:
			dp[k + lista[i]] = dp[k].copy()
			dp[k + lista[i]][i] = 1
			
	dp[lista[i]] = {}
	dp[lista[i]][i] = 1
		
primeiro = [] 
segundo = []

if dp[target] == 0 or n == 1 or sum(lista) % 2:
	print(-1)
else:
	for i in range(0, n):
		if (dp[target].get(i) == 1):
			primeiro.append(lista[i])
		else:
			segundo.append(lista[i]) 

	soma = 0
	ind1 = 0
	ind2 = 0
	for i in range(0, n):
		if soma > 0:
			print(primeiro[ind1], end=" ")
			soma -= primeiro[ind1]
			ind1 += 1
		else:
			print(segundo[ind2], end=" ")
			soma += segundo[ind2]
			ind2 += 1
	print()
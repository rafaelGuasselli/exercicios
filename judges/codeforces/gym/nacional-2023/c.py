from random import random, seed


n, k = map(int, input().split())
a = list(map(int, input().split()))
seed(34672789374)  
value = [round(random() * 1e12) for _ in range(k - 1)]
value.append(-sum(value))

dict = {
	0: 0
}

soma = 0
maximo = 0
for i in range(n):
	soma +=  value[a[i]-1]
	if soma not in dict:
		dict[soma] = i+1
		
	maximo = max(maximo, i+1-dict[soma])

print(maximo)
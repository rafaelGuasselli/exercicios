pol = 0
n = int(input())
lista = list(map(int, input().split()))

for i in range(n, -1, -1):
	pol += (1<<(n-i)) * lista[i]

count = 0
while pol != 1:
	newPol = 1
	if pol & 1:
		for i in range(64):
			if pol & (1<<i):
				newPol = newPol ^ (1<<(i+1))
				newPol = newPol ^ (1<<i)
	else:
		newPol = pol>>1

	pol = newPol
	count += 1
print(count)

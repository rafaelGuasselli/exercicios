n = int(input())

numeros = []
previous, current = 0, 1
for i in range(0, n):
	numeros.append(current)
	previous, current = current, previous+current

for i in range(1, len(numeros)+1):
	print(numeros[-i], end=" " if i != (len(numeros)) else "")
print()
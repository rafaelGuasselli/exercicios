numFrases = int(input())

for i in range(0, numFrases):
	frase = input().split()
	frase.sort(key=lambda a: -len(a))
	for j in range(0, len(frase)):
		print(frase[j], end=" " if j < len(frase) - 1 else "")
	print()	
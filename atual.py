n = int(input())
a = list(map(int, input().split()))


mudanca = []
prev = 0
for i in range(n):
	if a[i] != 0 and i!=prev:
		mudanca.append((prev, i, a[i]>a[prev]))
		prev = i
mudanca.append((prev, n-1, a[n-1]>a[prev]))

mudancasUnicas = []
mudancaAtual = mudanca[0]
for i in range(1, len(mudanca)):
	p1, n1, c1 = mudanca[i-1]
	p2, n2, c2 = mudanca[i]

	if c1 == c2:
		mudancaAtual = (mudancaAtual[0], n2, c2)
	else:
		mudancasUnicas.append(mudancaAtual)
		mudancaAtual = mudanca[i]
mudancasUnicas.append(mudancaAtual)

print(mudancasUnicas)
if len(mudancasUnicas) > 2:
	print("*")
elif len(mudancaAtual) == 1:
	print(list(range(n, 0, -1)))
elif len(mudancasUnicas) == 2 and mudanca[0][2] and not mudanca[1][2]:
	possivel = [i for i in range(1, n+1) if i not in a]
	left = [i for i in possivel if i in possivel and i >= a[mudanca[0][0]] and i <= a[mudanca[0][1]]]
	right = [i for i in possivel if i in possivel and i <= a[mudanca[1][0]] and i >= a[mudanca[1][1]]]

	limite = mudanca[1][0]
	for i in range(n):
		if a[i] != 0:
			if i < limite:
				val = left.pop(0)
				a[i] = left.pop(0)
				
			else:
				a[i] = right.pop(0)
	print(left)
	print(right)
else:
	print("*")
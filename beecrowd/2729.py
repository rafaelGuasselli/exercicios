qtdTestes = int(input())
for i in range(0, qtdTestes):
	linha = input().split()
	compras = sorted(set(linha))
	for item in compras:
		print(item, end=" " if item != compras[len(compras)-1] else "")
	print()
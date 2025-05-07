n = int(input())
while n:
	n-=1

	entrada = input()
	abertura = 0
	diamante = 0

	for i in entrada:
		if i == "<":
			abertura += 1
		elif i == ">" and abertura > 0:
			diamante += 1
			abertura -=1
	
	print(diamante)
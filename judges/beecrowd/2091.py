def ex(entrada):
	qtdNums = int(entrada)
	numeros = list(map(int, input().split()))
	frequencias = {}
	for num in numeros:
		if num in frequencias:
			frequencias[num] += 1
		else:
			frequencias[num] = 1
	for numero in frequencias:
		if frequencias[numero] % 2 != 0:
			print(numero)

while True:
	entrada = input()
	if entrada == "0":
		break
	ex(entrada)
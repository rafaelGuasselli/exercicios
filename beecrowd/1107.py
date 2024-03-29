def ex(entrada):
	altura, comprimento = map(int, entrada.split())
	alturaDosBlocos = list(map(int, input().split()))
	ordemBlocos = []

	alturaDosBlocos.append(altura)
	qtdLaser = 0
	for i in range(0, comprimento):
		if alturaDosBlocos[i] < alturaDosBlocos[i+1]:
			qtdLaser += alturaDosBlocos[i+1] - alturaDosBlocos[i]
	print(qtdLaser)

while True:
	entrada = input()
	if entrada == "0 0":
		break
	ex(entrada)
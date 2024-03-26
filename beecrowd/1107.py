def ex(entrada):
	altura, largura = map(int, entrada.split())
	alturaDeCadaPilar = map(int, input().split())

	camada = altura - max(alturaDeCadaPilar)
	qtdAtivacoesLaser = camada
	
	#Find amount of peeks on layer
	


while True:
	entrada = input()
	if entrada == "0 0":
		break
	ex(entrada)
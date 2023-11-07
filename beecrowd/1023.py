
#TODO: Terminar isso.
def ex(entrada):
	qtdTeste = int(entrada)

	consumos = {}
	totalConsumido = 0
	totalPessoas = 0
	for i in range(0, qtdTeste):
		qtdPessoas, consumo = map(int, input().split())
		if not consumo//qtdPessoas in consumos:
			consumos[consumo//qtdPessoas] = 0
		consumos[consumo//qtdPessoas] += qtdPessoas
		totalConsumido += consumo
		totalPessoas += qtdPessoas
	
	
	consumos = sorted(consumos)
	contador = 0
	for mediaConsumo in consumos:
		print(mediaConsumo)
		print("{:n}-{:n}".format(consumos[mediaConsumo], mediaConsumo), end=" " if contador < len(consumos) - 1 else "")
		contador += 1
	
	print("Consumo medio: {:.2f} m3.".format(totalConsumido/totalPessoas))

	
contador = 1
while True:
	entrada = input()
	if entrada == "0":
		break
	
	print("Cidade# {:n}:".format(contador))
	ex(entrada)
	print()
	contador += 1
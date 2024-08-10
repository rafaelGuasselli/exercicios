def qtdDiferencas(assinatura1, assinatura2):
	totalDif = 0
	for i in range(0, len(assinatura1)):
		totalDif += 1 if assinatura1[i] != assinatura2[i] else 0
	return totalDif

def ex(entrada):
	qtdAlunos = int(entrada)
	assinaturasOriginais = {}
	for i in range(0, qtdAlunos):
		nome, assinatura = input().split()
		assinaturasOriginais[nome] = assinatura

	qtdAssinaturas = int(input())
	totalFalsas = 0
	for i in range(0, qtdAssinaturas):
		nome, assinatura = input().split()
		totalFalsas += 1 if qtdDiferencas(assinaturasOriginais[nome], assinatura) > 1 else 0
	print(totalFalsas)


while True:
	entrada = input()
	if entrada == "0":
		break
	ex(entrada)
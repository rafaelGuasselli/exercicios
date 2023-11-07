def rerankear(colocacaoNasCorridas, sistema, qtdPilotos):
	pontos = []
	for i in range(0, qtdPilotos):
		pontos.append([0, i + 1])

	for colocacao in colocacaoNasCorridas:
		for i in range(0, sistema[0]):
			piloto = colocacao[i] - 1
			pontos[piloto][0] += sistema[1:][i] 
	pontos.sort(reverse=True)
	return pontos

def acharCampeoes(pontos):
	campeoes = []

	for i in range(1, len(pontos)+1):
		campeoes.append(pontos[i-1][1])
		if i < len(pontos) and pontos[i-1][0] > pontos[i][0]:
			break
	campeoes.sort()
	return campeoes


def ex(entrada):
	qtdCorridas, qtdPilotos = map(int, entrada.split())
	colocacaoNasCorridas = []
	for i in range(0, qtdCorridas):
		colocacao = list(map(int, input().split()))
		colocacaoNasCorridas.append(colocacao)

	sitemasDePontos = []
	qtdSistemasDePontos = int(input())
	for i in range(0, qtdSistemasDePontos):
		sistema = list(map(int, input().split()))
		sitemasDePontos.append(sistema)

	for sistema in sitemasDePontos:
		ranking = rerankear(colocacaoNasCorridas, sistema, qtdPilotos)
		print(ranking)
		campeoes = acharCampeoes(ranking)
		if len(campeoes) == 1:
			print(campeoes[0])
		else:
			for campeao in campeoes:
				print(campeao, end=" " if campeao != campeoes[len(campeoes) - 1] else "")
			print()





while True:
	entrada = input()
	if entrada == "0 0":
		break
	ex(entrada)
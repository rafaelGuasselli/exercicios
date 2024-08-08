def acharCampeoes(resultados, sistemaDePontuacao, qtdPilotos):
	pontosRecalculados = [0] * qtdPilotos
	for resultado in resultados:
		for i in range(qtdPilotos):
			posPilotoAtual = resultado[i] - 1
			if posPilotoAtual < len(sistemaDePontuacao):
				pontosRecalculados[i] += sistemaDePontuacao[posPilotoAtual]
	
	maiorPontuacao = 0
	campeoes = []

	for i in range(qtdPilotos):
		pontuacaoPiloto = pontosRecalculados[i]
		if pontuacaoPiloto > maiorPontuacao:
			maiorPontuacao = pontuacaoPiloto
			campeoes = []
			
		if pontuacaoPiloto == maiorPontuacao:
			campeoes.append(i+1)
	return campeoes

def ex(entrada):
	qtdGrandesPremios, qtdPilotos = map(int, entrada.split())

	resultados = []
	for i in range(qtdGrandesPremios):
		resultadoCorrida = list(map(int, input().split()))
		resultados.append(resultadoCorrida)

	qtdSistemasPontuacao = int(input())
	for i in range(qtdSistemasPontuacao):
		sistemaPontuacao = list(map(int, input().split()))[1:]
		campeoes = acharCampeoes(resultados, sistemaPontuacao, qtdPilotos)
		print(*campeoes)

while True:
	entrada = input()
	if entrada == "0 0":
		break
	ex(entrada)
qtdFigurinhas = int(input())
frequencias = {}

#Acha a frequencia com que cada figurinha aparece
for i in range(0, qtdFigurinhas):
	idFig = input()
	if not idFig in frequencias:
		frequencias[idFig] = 0
	frequencias[idFig] += 1

totalDiferentes = 0
totalRepetidas = 0
#Conta o total de figurinhas diferentes vendo se a frequencia > 0 e somando 1
#Conta as repetidas tirando 1 pq é a unica diferente
for idFig in frequencias:
	val = frequencias[idFig]
	totalDiferentes += min(val, 1)
	totalRepetidas += val - 1
print(totalDiferentes)
print(totalRepetidas)
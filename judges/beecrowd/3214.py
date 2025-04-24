from math import floor
numeroDeGarrafasVaziasAtual, numeroDeGarrafasVaziasEncontradas, numeroDeGarrafasPorNovaGarrafa = map(int, input().split())

numeroTotalGarrafasBebidas = 0
numeroDeGarrafasVaziasAtual = numeroDeGarrafasVaziasAtual + numeroDeGarrafasVaziasEncontradas

#A cada iteração tem que verificar quantas novas garrafas vazias foram geradas
#E quantas novas garrafas são geradas a partir das geradas na iteração anterior

while(numeroDeGarrafasVaziasAtual >= numeroDeGarrafasPorNovaGarrafa): #Loopa até não ser possível retornar garrafas
    numeroDeGarrafasNovas = floor(numeroDeGarrafasVaziasAtual/numeroDeGarrafasPorNovaGarrafa) #Acha o numero de garrafas geradas
    numeroTotalGarrafasBebidas += numeroDeGarrafasNovas
    numeroDeGarrafasVaziasAtual -= (numeroDeGarrafasNovas * numeroDeGarrafasPorNovaGarrafa) #Remove as garrafas retornadas
    numeroDeGarrafasVaziasAtual += numeroDeGarrafasNovas #Adiciona as garrafas geradas nessa iteração
print(numeroTotalGarrafasBebidas)
from functools import reduce
qtdQuestoes = int(input())
gabaritoDesafortunado = list(input())
qtdAlunos = int(input())

totalAcertos = 0
frequenciaResposta = [{} for i in range(qtdQuestoes)] 
maiorRespostas = [0] * qtdQuestoes 

for i in range(qtdAlunos):
	respostas = list(input())
	for j in range(0, len(respostas)):
		resposta = respostas[j]
		if resposta == gabaritoDesafortunado[j]: continue
		
		if resposta not in frequenciaResposta[j]:
			frequenciaResposta[j][resposta] = 0
		frequenciaResposta[j][resposta] += 1
		
		if frequenciaResposta[j][resposta] > maiorRespostas[j]:
			maiorRespostas[j] = frequenciaResposta[j][resposta]

print(reduce(lambda a,b:a+b, maiorRespostas))
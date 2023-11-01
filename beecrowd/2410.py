qtdRegistros = int(input())
frequencias = {}

#Pega as frequencias que cada aluno aparece nos registros
for i in range(0, qtdRegistros):
	idAluno = input()
	if not idAluno in frequencias:
		frequencias[idAluno] = 0
	frequencias[idAluno] += 1

totalDiferentes = 0
for idAluno in frequencias:
	val = frequencias[idAluno]
	#Soma 0 caso não tenha nenhuma frequencia
	#Soma 1 caso frequencia > 0, já que mesmo que tenha + que 1 continua sendo só um aluno
	totalDiferentes += min(val, 1)
print(totalDiferentes)
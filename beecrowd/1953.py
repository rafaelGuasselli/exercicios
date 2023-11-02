def ex(entrada):
	qtdAlunos = int(entrada)
	turmas = {
		"EPR": 0,
		"EHD": 0,
		"INTRUSOS": 0
	}
	for i in range(0, qtdAlunos):
		matricula, turma = input().split()
		if turma in turmas:
			turmas[turma] += 1
		else:
			turmas["INTRUSOS"] += 1
			
	print("EPR: {:n}".format(turmas["EPR"]))
	print("EHD: {:n}".format(turmas["EHD"]))
	print("INTRUSOS: {:n}".format(turmas["INTRUSOS"]))


while True:
	try:
		entrada = input()
		ex(entrada)
	except EOFError:
		break
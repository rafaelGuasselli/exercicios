import sys
from array import array

sys.setrecursionlimit(10 ** 8)

def dfs(node):	
	node["menorIdade"] = 101

	for patrao in node["patroes"]:
		node["menorIdade"] =  min(node["menorIdade"], patrao["menorIdade"], patrao["idade"])

	for empregado in node["empregados"]:
		dfs(empregado)

def empregar(empregados, patrao, empregado):
	empregados[empregado - 1]["patroes"].append(empregados[patrao - 1])
	empregados[patrao - 1]["empregados"].append(empregados[empregado - 1])

def makeNode(idade):
	return {
		"idade": idade,
		"menorIdade": 101,
		"patroes": [],
		"empregados": [],
	}
		
def ex(entrada):
	qtdEmpregados, qtdRelacoes, qtdInstrucoes = map(int, entrada.split())

	idades = array("i")
	linha = input().split()
	while(len(linha) > 2):
		idades.extend(list(map(int, linha)))
		linha = input().split()

	empregados = array("o")
	for i in range(0, qtdEmpregados):
		empregados.append(makeNode(idades[i]))

	patrao, empregado = map(int, linha)
	empregar(empregados, patrao, empregado)
	lista = []
	for i in range(0, qtdRelacoes-1):
		patrao, empregado = map(int, input().split())
		lista.append(empregado-1)
		empregar(empregados, patrao, empregado)

	for i in range(0, qtdEmpregados):
		if not i in lista:
			dfs(empregados[i]) 

	for i in range(0, qtdInstrucoes):
		instrucao = input()
		
		if "P" in instrucao:
			empregado = int(instrucao[2:])
			print("*" if empregados[empregado-1]["menorIdade"] == 101 else empregados[empregado-1]["menorIdade"])
		elif "T" in instrucao:
			a, b = map(int, instrucao[1:].split())

			empregados[a-1]["idade"], empregados[b-1]["idade"] = empregados[b-1]["idade"], empregados[a-1]["idade"]
			empregados[a-1], empregados[b-1] = empregados[b-1], empregados[a-1]
			empregados[a-1]["menorIdade"] = 101
			empregados[b-1]["menorIdade"] = 101

			if empregados[b-1]["idade"] < empregados[b-1]["menorIdade"] and empregados[a-1]["idade"] < empregados[b-1]["idade"]:
				dfs(empregados[a-1])
				dfs(empregados[b-1])
			if empregados[a-1]["idade"] < empregados[a-1]["menorIdade"] and empregados[b-1]["idade"] < empregados[a-1]["idade"]:
				dfs(empregados[a-1])
				dfs(empregados[b-1])
while True:
	try:
		entrada = input()
		ex(entrada)
	except EOFError:
		break
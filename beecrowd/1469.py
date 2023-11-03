import sys
sys.setrecursionlimit(10 ** 8)

def dfs(node, menorIdade):
	idades = [menorIdade]
	for patrao in node["patroes"]:
		idades.append(patrao["idade"])
		idades.append(dfs(patrao, menorIdade))
	return min(idades)

def swap(empregados, a, b):
	nodeA = empregados[a-1]
	nodeB = empregados[b-1]

	patroesA = nodeA["patroes"].copy()
	patroesB = nodeB["patroes"].copy()
	empregadosA = nodeA["empregados"].copy()
	empregadosB = nodeB["empregados"].copy()

	for patrao in patroesA:
		patrao["empregados"].remove(nodeA)
		patrao["empregados"].append(nodeB)

	for patrao in patroesB:
		patrao["empregados"].remove(nodeB)
		patrao["empregados"].append(nodeA)

	for empregado in empregadosA:
		empregado["patroes"].remove(nodeA)
		empregado["patroes"].append(nodeB)

	for empregado in empregadosB:
		empregado["patroes"].remove(nodeB)
		empregado["patroes"].append(nodeA)
	
	nodeA["patroes"], nodeB["patroes"] = nodeB["patroes"], nodeA["patroes"]
	nodeA["empregados"], nodeB["empregados"] = nodeB["empregados"], nodeA["empregados"]
	
	if nodeA["patroes"] == nodeA:
		nodeA["patroes"], nodeB["empregados"] = nodeB["empregados"], nodeA["patroes"]

	if nodeB["patroes"] == nodeB:
		nodeB["patroes"], nodeA["empregados"] = nodeA["empregados"], nodeB["patroes"]

def empregar(empregados, patrao, empregado):
	empregados[empregado - 1]["patroes"].append(empregados[patrao - 1])
	empregados[patrao - 1]["empregados"].append(empregados[empregado - 1])

def makeNode(id, idade):
	return {
		"id": id,
		"idade": idade,
		"patroes": [],
		"empregados": [],
	}
		

def ex(entrada):
	qtdEmpregados, qtdRelacoes, qtdInstrucoes = map(int, entrada.split())
	
	idades = []
	linha = input().split()
	while(len(linha) > 2):
		idades.extend(list(map(int, linha)))
		linha = input().split()

	empregados = []
	for i in range(0, qtdEmpregados):
		empregados.append(makeNode(i+1, idades[i]))

	patrao, empregado = map(int, linha)
	empregar(empregados, patrao, empregado)
	for i in range(0, qtdRelacoes-1):
		patrao, empregado = map(int, input().split())
		empregar(empregados, patrao, empregado)

	for i in range(0, qtdInstrucoes):
		instrucao = input()
		
		if "P" in instrucao:
			empregado = int(instrucao[2:])
			menorIdade = dfs(empregados[empregado - 1], 101)
			print("*" if menorIdade == 101 else menorIdade)
		elif "T" in instrucao:
			a, b = map(int, instrucao[1:].split())
			swap(empregados, a, b)

while True:
	try:
		entrada = input()
		ex(entrada)
	except EOFError:
		break
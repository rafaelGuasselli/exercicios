import sys
sys.setrecursionlimit(10 ** 8)

def dfs(node, visitados, menorIdade):
	visitados[node["id"]] = 1
	for patrao in node["patroes"]:
		if visitados[patrao["id"]] == 0:
			menorIdade = min(dfs(patrao, visitados, menorIdade), patrao["idade"])
	return menorIdade

def makeNode(id, idade):
	return {
		"id": id, 
		"idade": idade,
		"patroes": []
	}
		
def ex(entrada):
	qtdEmpregados, qtdRelacoes, qtdInstrucoes = map(int, entrada.split())
	idades = list(map(int, input().split()))
	
	empregados = []
	for i in range(0, qtdEmpregados):
		empregados.append(makeNode(i, idades[i]))

	for i in range(0, qtdRelacoes):
		patrao, empregado = map(int, input().split())
		empregados[empregado - 1]["patroes"].append(empregados[patrao - 1])

	for i in range(0, qtdInstrucoes):
		instrucao = input()
		
		if "P" in instrucao:
			empregado = int(instrucao[2:])
			menorIdade = dfs(empregados[empregado - 1], [0] * qtdEmpregados, 101)
			print("*" if menorIdade == 101 else menorIdade)
		elif "T" in instrucao:
			a, b = map(int, instrucao[1:].split())

			empregados[a-1]["idade"], empregados[b-1]["idade"] = empregados[b-1]["idade"], empregados[a-1]["idade"]
			empregados[a-1], empregados[b-1] = empregados[b-1], empregados[a-1]

while True:
	try:
		entrada = input()
		ex(entrada)
	except EOFError:
		break
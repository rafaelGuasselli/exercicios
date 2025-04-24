import sys
sys.setrecursionlimit(10**8)

def dfs(node, visitados):
	visitados[node["indice"]] = True
	for child in node["filhos"]:
		if not visitados[child["indice"]]:
			dfs(child, visitados)

def makeNode(indice):
	return {
		"indice": indice,
		"filhos": []
	}

qtdCidades, qtdFronteiras = map(int, input().split())
visitados = [False] * qtdCidades
nodes = []

for i in range(0, qtdCidades):
	nodes.append(makeNode(i))

for i in range(0, qtdFronteiras):
	a, b = map(int, input().split())
	nodes[a-1]["filhos"].append(nodes[b-1])
	nodes[b-1]["filhos"].append(nodes[a-1])

contador = 0
for i in range(0, qtdCidades):
	if not visitados[i]:
		contador += 1
		dfs(nodes[i], visitados)
print(contador)
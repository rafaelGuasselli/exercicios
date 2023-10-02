numCasas = int(input())

campoMinado = [0] * numCasas
for i in range(0, numCasas):
    bomba = int(input())
    campoMinado[i] += bomba
    if i > 0:
        campoMinado[i - 1] += bomba
    if i < numCasas-1:
        campoMinado[i + 1] += bomba

for i in campoMinado:
    print(i)
from functools import reduce
def testarColunas(matrix):
    for l in range(0, 9):
        teste = [0] * 10
        for c in range(0, 9):
            if teste[vetor[i]] == 1:
                return False
            teste[vetor[i]] = 1
    return True

def testarLinhas(matrix):
    for l in range(0, 9):
        teste = [0] * 10
        for c in range(0, 9):
            if teste[vetor[l][]] == 1:
                return False
            teste[vetor[i]] = 1
    return True


def ex():
    matrix = [] 
    for l in range(0, 9):
        linha = input().split()
        matrix.append(linha)
    

numeroDeTestes = int(input())

for i in range(0, numeroDeTestes):
    print("Instancia {:n}".format(i + 1))
    ex()
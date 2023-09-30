def ex(entrada):
    numBilhetes, numPessoas = map(int, entrada.split())
    bilhetes = list(map(int, input().split()))
    repetidos = [0] * numBilhetes
    totalRepetidos = 0

    for i in range(0, numPessoas):
        repetidos[bilhetes[i] - 1] += 1
        if repetidos[bilhetes[i] - 1] == 2:
            totalRepetidos += 1
    print(totalRepetidos)

while True:
    entrada = input()
    if entrada == "0 0":
        break
    ex(entrada)
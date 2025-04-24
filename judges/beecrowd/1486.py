def ex1486(entrada):
    numeroDePontos, medicoes, comprimentoMinimo = map(int, entrada.split())
    palitos = [0] * numeroDePontos
    qtdPalitosValidos = 0
    for i in range(0, medicoes):
        pontos = list(map(int, input().split()))
        for j in range(0, numeroDePontos):
            if pontos[j] == 1:
                palitos[j] += 1
            else:
                palitos[j] = 0
            if palitos[j] >= comprimentoMinimo:
                qtdPalitosValidos += 1
                palitos[j] = -2 * medicoes
    print(qtdPalitosValidos)

while True:
    entrada = input()
    if entrada == "0 0 0":
        break

    ex1486(entrada)


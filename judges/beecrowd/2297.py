def ganhador(numeroDeRodadas):
    totalA, totalB = 0, 0
    for i in range(0, numeroDeRodadas):
        a, b = map(int, input().split())
        totalA += a
        totalB += b
    if totalA > totalB:
        return "Aldo"
    else: 
        return "Beto"

entrada = int(input())
numeroTeste = 1
while entrada != 0:
    vencedor = ganhador(entrada)
    print("Teste {:n}".format(numeroTeste))
    numeroTeste += 1
    print(vencedor)
    print()

    entrada = int(input())
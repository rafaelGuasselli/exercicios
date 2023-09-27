from functools import reduce
def ex2231(entrada):
    numMedidas, intervalo = map(int, entrada.split())
    media = 0

    temps = [int(input()) for i in range(0, numMedidas)]
    media = reduce(lambda a, b: a + b, temps[0:intervalo], 0)    
    mediaMenor = media
    mediaMaior = media

    for i in range(intervalo, numMedidas):
        media -= temps[i - intervalo]
        media += temps[i]
        mediaMaior = max(mediaMaior, media)
        mediaMenor = min(mediaMenor, media)

    mediaMenor = int(mediaMenor / intervalo)
    mediaMaior = int(mediaMaior / intervalo)
    print("{:n} {:n}".format(mediaMenor, mediaMaior))
        

numTeste = 1
while True:
    entrada = input()
    if entrada == "0 0":
        break
    print("Teste {:n}".format(numTeste))
    ex2231(entrada)
    print()
    numTeste += 1
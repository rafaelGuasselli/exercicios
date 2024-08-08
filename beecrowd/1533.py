def ex(entrada):
    numSuspeitos = int(entrada)
    arrayDeSuspeitos = list(map(int, input().split()))
    arrayOrdenadoDeSuspeitos = arrayDeSuspeitos.copy()
    arrayOrdenadoDeSuspeitos.sort(reverse=True)
    indexDoSegundoMaisSuspeito = arrayDeSuspeitos.index(arrayOrdenadoDeSuspeitos[1]) + 1
    print(indexDoSegundoMaisSuspeito)

while True:
    entrada = input()
    if entrada == "0":
        break
    ex(entrada)
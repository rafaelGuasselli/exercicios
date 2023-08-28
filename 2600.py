from functools import reduce
numeroDeTeste = int(input())

for i in range(0, numeroDeTeste):
    ladoDecima = int(input())
    ladoDaEsquerda, ladoDaFrente, ladoDaDireita, ladoDeTras = map(int, input().split())
    ladoDeBaixo = int(input())

    lados = [ladoDecima, ladoDaEsquerda, ladoDaFrente, ladoDaDireita, ladoDeTras, ladoDeBaixo]
    lados.sort()

    temTodosOsNumeros = True
    for j in range(len(lados)):
        if lados[j] != (j + 1):
            temTodosOsNumeros = False
            break

    validarEixoX = (ladoDaEsquerda + ladoDaDireita) == 7
    validarEixoZ = (ladoDaFrente + ladoDeTras) == 7
    validarEixoY = (ladoDecima + ladoDeBaixo) == 7
    dadoClassico = temTodosOsNumeros and validarEixoX and validarEixoY and validarEixoZ

    if dadoClassico:
        print("SIM")
    else:
        print("NAO")
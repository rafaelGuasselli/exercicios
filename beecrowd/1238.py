from math import ceil
numeroCasosDeTeste = int(input())

for i in range(0, numeroCasosDeTeste):
    palavras = input().split()
    resultado = ""

    for j in range(0, min(len(palavras[0]), len(palavras[1]))):
        resultado += palavras[0][j]
        resultado += palavras[1][j]
    
    if len(palavras[0]) < len(palavras[1]):
        resultado += palavras[1][len(palavras[0]):]
    else:
        resultado += palavras[0][len(palavras[1]):]

    print(resultado)
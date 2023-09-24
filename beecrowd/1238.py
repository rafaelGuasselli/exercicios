from math import ceil
numeroCasosDeTeste = int(input())

for i in range(0, numeroCasosDeTeste):
    palavra1, palavra2 = input().split()
    resultado = ""
    for j in range(1, min(len(palavra1), len(palavra2))+1):
        turno = j % 2

        if turno == 1:
            #1, 3, 5, 7, 9
            #0, 1, 2, 3, 4
            resultado += palavra1[j - ceil(j/2)]
        if turno == 0:
            #2, 4, 6, 8, 10
            #0, 1, 2, 3, 4
            resultado += palavra1[j - 1 - ceil(j/2)]
    
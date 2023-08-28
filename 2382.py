from math import sqrt, pow
dimensoesDaCaixa = list(map(lambda a: int(a), input().split()))
diametroDaEsfera = dimensoesDaCaixa.pop() * 2

raioDaEsfera = diametroDaEsfera/2
diagonalDoCuboid = sqrt(pow(dimensoesDaCaixa[0], 2) + pow(dimensoesDaCaixa[1], 2) + pow(dimensoesDaCaixa[2], 2))
cabeNaCaixa = diagonalDoCuboid <= diametroDaEsfera

print("S" if cabeNaCaixa else "N") 
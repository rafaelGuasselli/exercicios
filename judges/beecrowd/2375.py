from functools import reduce

diametroDaEsfera = int(input())
dimensoesDaCaixa = list(map(lambda a: int(a), input().split()))
dimensoesDaCaixa.sort()

raioDaEsfera = diametroDaEsfera/2
volumeDaEsfera = 4/3 * raioDaEsfera ** 3
volumeDaCaixa = reduce(lambda a, b: a * b, dimensoesDaCaixa)
cabeNaCaixa = volumeDaEsfera <= volumeDaCaixa and dimensoesDaCaixa[0] >= diametroDaEsfera

print("S" if cabeNaCaixa else "N")
from math import log2, floor
lado = float(input())
totalDeDivisoes = floor(log2(lado))
totalDePedacos = 2**(totalDeDivisoes*2)
print(totalDePedacos)
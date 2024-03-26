from functools import reduce;

qtdCortes = int(input())
cortes = list(map(int, input().split()))
resto = reduce(lambda a,b: a+b, cortes) - qtdCortes

print(resto)
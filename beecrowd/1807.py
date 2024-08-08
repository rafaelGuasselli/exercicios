#TODO: Study this https://github.com/python/cpython/blob/109fc2792a490ee5cd8a423e17d415fbdedec5c8/Objects/longobject.c#L4244-L4447
# and this https://en.wikipedia.org/wiki/Exponentiation_by_squaringhttps://en.wikipedia.org/wiki/Exponentiation_by_squaring

M = 2147483647
n = int(input())
print(pow(3, n, M))
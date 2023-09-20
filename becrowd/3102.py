from math import pow, sqrt
def distanciaEntrePontos(p1, p2):
    return sqrt(pow(p1[0] - p2[0], 2) + pow(p1[1] - p2[1], 2))

def formulaHeron(a, b, c):
    p = (a + b + c)/2
    return sqrt(p * (p - a) * (p - b) * (p - c))

numeroDeTestes = int(input())
for i in range(0, numeroDeTestes):
    pontosDoTriangulo = list(map(int, input().split()))
    p1 = (pontosDoTriangulo[0], pontosDoTriangulo[1])
    p2 = (pontosDoTriangulo[2], pontosDoTriangulo[3])
    p3 = (pontosDoTriangulo[4], pontosDoTriangulo[5])
    a, b, c = [distanciaEntrePontos(p1, p2), distanciaEntrePontos(p2, p3), distanciaEntrePontos(p3, p1)]
    print("{:.3f}".format(formulaHeron(a,b,c)))
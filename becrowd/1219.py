from math import sqrt
M_PI = 3.1415926535897
def eofInput():
    try:
        return input()
    except EOFError:
        return False

entrada = eofInput()
while (entrada):
    ladosTriangulo = list(map(int, entrada.split()))
    c,b,a = ladosTriangulo

    p = (a+b+c)/2
    areaDoTriangulo = sqrt(p * (p - a) * (p - b) * (p - c))

    raioDoCirculoInterno = (2 * areaDoTriangulo)/(a+b+c)
    areaDoCirculoInterno = M_PI * (raioDoCirculoInterno ** 2)
    
    raioDoCirculoExterno = (a * b * c)/(4 * areaDoTriangulo)
    areaDoCirculoExterno = M_PI * (raioDoCirculoExterno ** 2)

    girasois = areaDoCirculoExterno - areaDoTriangulo
    violetas = areaDoTriangulo - areaDoCirculoInterno
    rosas = areaDoCirculoInterno

    print("{:.4f} {:.4f} {:.4f}".format(girasois, violetas, rosas))

    entrada = eofInput()
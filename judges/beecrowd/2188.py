def interseccao(numeroDeRegioes):
    ix0, iy0, ix1, iy1 = [-10001, 10001, 10001, -10001]
    for i in range(0, numeroDeRegioes):
        x0, y0, x1, y1 = list(map(int, input().split()))
        ix0 = max(x0, ix0)
        iy0 = min(y0, iy0)
        ix1 = min(x1, ix1)
        iy1 = max(y1, iy1)

    if ix0 < ix1 and iy0 > iy1:
        return [ix0, iy0, ix1, iy1]

entrada = int(input())
numeroTeste = 1
while entrada != 0:
    regiaoDaInterseccao = interseccao(entrada)
    print("Teste {:n}".format(numeroTeste))
    numeroTeste += 1
    if regiaoDaInterseccao == None:
        print("nenhum")
    else: 
        print(*regiaoDaInterseccao)
    print()

    entrada = int(input())
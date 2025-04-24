def rafael(x, y):
    return (3 * x) ** 2 + y ** 2

def beto(x, y):
    return 2 * (x ** 2) + (5 * y) ** 2

def carlos(x, y):
    return -100 * x + y ** 3

numeroDeCasosDeTeste = int(input())
for i in range(0, numeroDeCasosDeTeste):
    x, y = map(int, input().split())
    lista = [(rafael(x, y), "Rafael"), (beto(x, y), "Beto"), (carlos(x, y), "Carlos")]
    lista.sort(reverse=True)
    print("{:s} ganhou".format(lista[0][1]))

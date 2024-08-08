qtdCasosTeste = int(input())

for i in range(0, qtdCasosTeste):
    arrayIdades = list(map(int, input().split()))
    arrayIdades.sort()
    print("Case {:n}: {:n}".format(i+1, arrayIdades[len(arrayIdades) // 2]))

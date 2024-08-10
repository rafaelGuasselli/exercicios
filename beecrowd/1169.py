from math import floor
numeroDeCasosDeTeste = int(input())

for i in range(0, numeroDeCasosDeTeste):
    quantidadeDeCasas = float(input())
    print("{:.0f} kg".format(floor(((2 ** quantidadeDeCasas) - 1)/12000)))
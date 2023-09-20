from math import sqrt;
def ex1247(entrada):
    distanciaXEntreBarcos, velocidadeBandido, velocidadeGuarda = map(int, entrada.split())

    hipotenusaAteAguasInternacionais = sqrt((distanciaXEntreBarcos ** 2) + (12 ** 2))
    tempoProBandidoEscapar = 12/velocidadeBandido
    tempoProGuardaChegar = hipotenusaAteAguasInternacionais/velocidadeGuarda

    print("S" if (tempoProGuardaChegar <= tempoProBandidoEscapar) else "N")

while (True):
    try:
        ex1247(input())
    except EOFError:
        break
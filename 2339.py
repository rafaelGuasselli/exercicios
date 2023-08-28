numeroDeCompetidores, numeroDeFolhasDePapel, numeroDeFolhasDePapelPorCompetidor = map(lambda a: int(a), input().split())
asFolhasSaoSuficientes = (numeroDeCompetidores * numeroDeFolhasDePapelPorCompetidor) <= numeroDeFolhasDePapel
print("S" if asFolhasSaoSuficientes else "N")
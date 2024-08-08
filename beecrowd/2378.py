numeroDeLeituras, limiteMaximoElevador = map(int, input().split())

quantidadeAtualDePassageiros = 0
passou = False
for i in range(0, numeroDeLeituras):
    saidas, entradas = map(int, input().split())
    quantidadeAtualDePassageiros += -saidas + entradas
    if quantidadeAtualDePassageiros > limiteMaximoElevador:
        passou = True

if passou:
    print("S")
else:
    print("N")
qtdPedras, numSapos = map(int, input().split())
pedras = [0] * qtdPedras
sapos = []

for i in range(0, numSapos):
    pos, taxaPulo = map(int, input().split())
    sapos.append((pos - 1, taxaPulo))

for i in range(0, qtdPedras):
    entra = False
    for j in range(0, numSapos):
        posSapo, taxaPuloSapo = sapos[j]
        if ((posSapo - i) % taxaPuloSapo) == 0:
            entra = True
            break
    print(int(entra))
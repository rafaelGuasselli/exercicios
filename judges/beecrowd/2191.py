numeroDePartidas = int(input())
numeroDoTeste = 1

while numeroDePartidas > 0:
    melhorSaldoTotal = 0
    melhorInicio = 0
    melhorFim = 0

    maiorPeriodo = 0
    saldoTotal = 0
    inicio = 0

    for i in range(0, numeroDePartidas):
        golsAFavor, golsContra = map(int, input().split())
        saldo = golsAFavor - golsContra
        saldoTotal += saldo
        if saldoTotal < 0:
            inicio = i + 1
            saldoTotal = 0
        else:
            periodo = i - inicio
            if (saldoTotal > melhorSaldoTotal or (saldoTotal == melhorSaldoTotal and periodo > maiorPeriodo)):  
                melhorSaldoTotal = saldoTotal
                melhorInicio = inicio
                melhorFim = i
                maiorPeriodo = periodo

    print("Teste {:n}".format(numeroDoTeste))
    numeroDoTeste += 1
    if melhorSaldoTotal <= 0:
        print("nenhum")
    else:
        print("{:n} {:n}".format(melhorInicio + 1, melhorFim + 1))
    print("")
    numeroDePartidas = int(input())
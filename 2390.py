TEMPO_FIXO = 10
tempoTotal = 0

numeroDePessoas = int(input())
tempoParaDesligar = 0
for i in range(0, numeroDePessoas):
    tempoInicial = int(input())
    tempoTotal += min(abs(TEMPO_FIXO - (tempoParaDesligar - tempoInicial)), TEMPO_FIXO)
    tempoParaDesligar = tempoInicial + TEMPO_FIXO
print(tempoTotal)
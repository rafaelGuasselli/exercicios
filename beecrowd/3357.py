from math import floor
qtdPessoas, qtdLitros, litrosQueCabemNaCuia = input().split()
qtdPessoas = int(qtdPessoas)
qtdLitros = float(qtdLitros)
litrosQueCabemNaCuia = float(litrosQueCabemNaCuia)

nomes = input().split()
rodada = qtdLitros/litrosQueCabemNaCuia

if rodada % 1 == 0:
    rodada -= 1
rodada = floor(rodada)

rico = nomes[rodada % qtdPessoas]
sobra = qtdLitros - litrosQueCabemNaCuia * rodada

print("{:s} {:.1f}".format(rico, sobra))
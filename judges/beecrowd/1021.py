from math import floor
valor = float(input())
notas = [100, 50, 20, 10, 5, 2]
moedas = [100, 50, 25, 10, 5, 1]

print("NOTAS:")
for i in range(0, len(notas)):
    quantidade = floor(valor/notas[i])
    print("{:n} nota(s) de R$ {:.2f}".format(quantidade, notas[i]))
    valor -= quantidade * notas[i]

print("MOEDAS:")
valor *= 100
for i in range(0, len(moedas)):
    quantidade = floor(valor/moedas[i])
    print("{:n} moeda(s) de R$ {:.2f}".format(quantidade, moedas[i]/100))
    valor -= quantidade * moedas[i]
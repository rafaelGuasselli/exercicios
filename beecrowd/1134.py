tipos = [0,0,0]
valor = 0

while valor != 4:
    valor = int(input())
    if valor > 0 and valor < 4:
        tipos[valor-1] += 1
print("MUITO OBRIGADO")
print("Alcool: {:n}".format(tipos[0]))
print("Gasolina: {:n}".format(tipos[1]))
print("Diesel: {:n}".format(tipos[2]))
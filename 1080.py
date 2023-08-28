maiorNumero = int()
maiorNumeroIndex = int()

for i in range(0, 100):
    valor = int(input())
    if valor > maiorNumero:
        maiorNumero = valor
        maiorNumeroIndex = i + 1
print(maiorNumero)
print(maiorNumeroIndex)
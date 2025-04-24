qtdElementos = int(input())
array = list(map(int, input().split()))

menorValor = array[0]
menorPos = 0

for i in range(0, qtdElementos):
    if array[i] < menorValor:
        menorValor = array[i]
        menorPos = i

print("Menor valor: {:n}".format(menorValor))
print("Posicao: {:n}".format(menorPos))
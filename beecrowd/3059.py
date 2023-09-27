tamanho, minimo, maximo = map(int, input().split())
pares = list(map(int, input().split()))

total = 0
for i in range(0, tamanho):
    for j in range(i+1, tamanho):
        soma = pares[i] + pares[j]
        if soma >= minimo and soma <= maximo:
            total += 1
print(total)
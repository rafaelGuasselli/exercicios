charDesejado = input()
frase = input().split()
total = 0

for palavra in frase:
    for i in range(0, len(palavra)):
        if palavra[i] == charDesejado:
            total += 1
            break

print("{:.1f}".format(100 * total/len(frase)))
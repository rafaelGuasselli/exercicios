bin = input()
num = int(bin, 2)

qtdDivs = int(input())
divisores = []
for i in range(0, qtdDivs):
    div = int(input())
    if num % div == 0:
        divisores.append(div)

divisores.sort()
for i in range(0, len(divisores)):
    print(divisores[i], end=" " if i + 1 < len(divisores) else "\n")

if len(divisores) == 0:
    print("Nenhum")
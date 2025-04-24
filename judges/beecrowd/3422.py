numDeCasos = int(input())

for i in range(0, numDeCasos):
    minutos, tempo = input().split()
    minutos = int(minutos)

    if tempo == "1T":
        resto = abs(min(0, 45 - minutos))
        minutos -= resto
        print(minutos, end="")
        if resto: print("+{:n}".format(resto), end="")
        print()
    else:
        resto = abs(min(0, 45 - minutos))
        minutos -= resto
        print(minutos + 45, end="")
        if resto: print("+{:n}".format(resto), end="")
        print()
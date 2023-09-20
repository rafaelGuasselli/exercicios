def numeroDeQuadrados(n):
    return (2 ** n + 1) * (2 ** n + 1)

entrada = input()
index = 1
while entrada != "-1":
    n = int(entrada)
    print("Teste {:n}".format(index))
    print(numeroDeQuadrados(n))
    print("")

    index += 1
    entrada = input()
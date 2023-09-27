def ex1140(entrada):
    palavras = entrada.lower().split()
    caracter = palavras[0][0]

    for i in range(1, len(palavras)):
        if palavras[i][0] != caracter:
            print("N")
            return
    print("Y")

entrada = input()
while entrada != "*":
    ex1140(entrada)
    entrada = input()
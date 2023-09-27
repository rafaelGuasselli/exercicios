def desenhar(primeiraFileira, segundaFileira):
    print(" ____________________________________________")
    print("|                                            |")
    print("|    ____________________________________    |_")
    print("|   |                                    |   |_)")
    print("|   |   8         4         2         1  |   |")
    print("|   |                                    |   |")
    print("|   |   {:s}         {:s}         {:s}         {:s}  |   |".format(primeiraFileira[0], primeiraFileira[1], primeiraFileira[2], primeiraFileira[3]))
    print("|   |                                    |   |")
    print("|   |                                    |   |")
    print("|   |   {:s}     {:s}     {:s}     {:s}     {:s}     {:s}  |   |".format(segundaFileira[0], segundaFileira[1], segundaFileira[2], segundaFileira[3], segundaFileira[4], segundaFileira[5]))
    print("|   |                                    |   |")
    print("|   |   32    16    8     4     2     1  |   |_")
    print("|   |____________________________________|   |_)")
    print("|                                            |")
    print("|____________________________________________|")
    print()

horasQuebradas = [8, 4, 2, 1]
minutosQuebradas = [32, 16, 8, 4, 2, 1]

def ex1561(entrada):
    horas, minutos = map(int, entrada.split(":"))
    primeiraFileira = []
    segundaFileira = []

    for i in range(0, 4):
        if horas >= horasQuebradas[i]:
            horas -= horasQuebradas[i]
            primeiraFileira.append("o")
        else:
            primeiraFileira.append(" ")

    for i in range(0, 6):
        if minutos >= minutosQuebradas[i]:
            minutos -= minutosQuebradas[i]
            segundaFileira.append("o")
        else:
            segundaFileira.append(" ")
    desenhar(primeiraFileira, segundaFileira)



while True:
    try:
        entrada = input()
        ex1561(entrada)
    except EOFError:
        break
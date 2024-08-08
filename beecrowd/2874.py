def ex(entrada):
    qtdBins = int(entrada)
    frase = ""

    for i in range(0, qtdBins):
        bin = input()
        frase += chr(int(bin, 2))
    print(frase)

while True:
    try:
        entrada = input()
        ex(entrada)
    except EOFError:
        break
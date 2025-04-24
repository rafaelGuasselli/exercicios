def ex(entrada):
    tamanho = int(entrada)
    for l in range(0, tamanho):
        for c in range(0, tamanho):
            valor = min(l + 1, c + 1, tamanho - l, tamanho - c)
            print("{:3d}".format(valor), end=" " if c < tamanho - 1 else "")
        print()

while True:
    entrada = input()
    if entrada == "0":
        break
    ex(entrada)
    print()
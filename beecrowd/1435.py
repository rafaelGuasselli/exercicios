def ex(entrada):
    tamanho = int(entrada)
    for l in range(0, tamanho):
        for c in range(0, tamanho):
            print("{:3d}".format(min(l, c, tamanho-l-1, tamanho-c-1) + 1), end=" ")
        print()

count = 0
while True:
    entrada = input()
    if entrada == "0":
        break
    if count > 0: 
        print()
    ex(entrada)
    count += 1
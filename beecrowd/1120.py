def ex1120(entrada):
    digitoError, texto = entrada.split()
    texto = texto.replace(digitoError, "")

    if texto:
        print(int(texto))
    else:
        print(0)

entrada = input()
while entrada != "0 0":
    ex1120(entrada)
    entrada = input()
from math import floor
def quantidadeDeNotas(valor):
    notas = [50, 10, 5, 1]

    saida = ""
    for i in range(0, len(notas)):
        quantidade = floor(valor/notas[i])
        saida += str(quantidade) + " "
        valor -= quantidade * notas[i]
    return saida.strip()


entrada = int(input())
indexDoTeste = 1
while entrada != 0:
    print("Teste {:n}".format(indexDoTeste))
    print(quantidadeDeNotas(entrada))
    print("")

    indexDoTeste += 1
    entrada = int(input())
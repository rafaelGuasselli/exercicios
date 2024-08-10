from functools import reduce
def ex(entrada):
    numJogadas = int(entrada)
    listaResultados = list(map(int, input().split()))
    vitoriasJoao = reduce(lambda a,b: a + b, listaResultados, 0)
    vitoriasMaria = numJogadas - vitoriasJoao
    print("Mary won {:n} times and John won {:n} times".format(vitoriasMaria, vitoriasJoao))

while True:
    entrada = input()
    if entrada == "0":
        break
    ex(entrada)
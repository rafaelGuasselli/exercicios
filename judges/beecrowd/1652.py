qtdPalavrasIrregulares, qtdPalavras = map(int, input().split())
vogais = ["a", "e", "i", "o", "u"]

def converterParaPlural(palavra, irregulares):
    ies = palavra[-1] == "y" and not palavra[-2] in vogais
    es = palavra[-1] == "o" or palavra[-1] == "s" or palavra[-1] == "x" or palavra[-2:] == "ch" or palavra[-2:] == "sh"

    if irregulares.get(palavra):
        return irregulares.get(palavra)
    elif ies:
        return palavra[:-1] + "ies"
    elif es:
        return palavra + "es"
    else:
        return palavra + "s"

irregulares = {}
for i in range(0, qtdPalavrasIrregulares):
    palavra, irregular = input().split()
    irregulares[palavra] = irregular

for i in range(0, qtdPalavras):
    palavra = input()
    print(converterParaPlural(palavra, irregulares))
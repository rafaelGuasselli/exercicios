
def peInverso(pe):
    return "D" if pe == "E" else "E"

def ex1245(entrada):
    numeroDeBotas = int(entrada)
    botas = {}
    pares = 0

    for i in range(0, numeroDeBotas):
        numero, pe = input().split()

        if botas.get(numero + peInverso(pe)) and botas[numero + peInverso(pe)] > 0:
            botas[numero + peInverso(pe)] -= 1
            pares += 1
        elif botas.get(numero + pe):  
            botas[numero + pe] += 1
        else:
            botas[numero + pe] = 1
    print(pares)
    
while True:
    try:
        entrada = input()
        ex1245(entrada)
    except EOFError:
        break
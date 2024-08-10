from math import ceil
entrada = input()
numeroDoTeste = 1

while(entrada != "0 0"):
    numeroDeRuas, numeroDeInteiros = map(int, entrada.split())
    numeroDeSufixos = ceil(numeroDeRuas/numeroDeInteiros) - 1

    if numeroDeSufixos <= 26:
        print("Case {:n}: {:n}".format(numeroDoTeste, numeroDeSufixos))
    else: 
        print("Case {:n}: impossible".format(numeroDoTeste))
        
    numeroDoTeste += 1
    entrada = input()
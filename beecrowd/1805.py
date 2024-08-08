numeros = input().split()
limiteInferior = int(numeros[0])
limiteSuperior = int(numeros[1])

numeroDeElementos = limiteSuperior - limiteInferior + 1
somaDosNaturais = (limiteInferior + limiteSuperior) * numeroDeElementos/2
print("{:.0f}".format(somaDosNaturais))
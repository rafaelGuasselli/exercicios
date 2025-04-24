from math import floor
numeroDeCasas = int(input())
numeroTotalDeCasasSemOMeio = numeroDeCasas * numeroDeCasas
numeroDeCasasPretas = floor(numeroTotalDeCasasSemOMeio/2)
numeroDeCasasBrancas = numeroDeCasasPretas

#O tabuleiro é uma grid quadrada, então você pode achar a quantidade de casas
#fazendo lado x lado
#Como o branco fica nos cantos ele vai ter uma casa a mais quando o lado é impar

if numeroDeCasas % 2 == 1: 
    numeroDeCasasBrancas+=1 


print("{:n} casas brancas e {:n} casas pretas".format(numeroDeCasasBrancas, numeroDeCasasPretas))
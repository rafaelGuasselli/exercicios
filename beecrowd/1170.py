from math import log2, ceil
numeroDeCasosDeTeste = int(input())

for i in range(0, numeroDeCasosDeTeste):
    quantidadeDeComida = float(input())
    print("{:n} dias".format(ceil(log2(quantidadeDeComida))))
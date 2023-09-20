numeroDeSupermercados = int(input())

menorValorPorGrama = 1000 # 1000 é o maior valor possível, então é util pra usar <
for i in range(0, numeroDeSupermercados):
    valorPor, gramas = input().split()
    valorPor = float(valorPor)
    gramas = int(gramas)
    valorPorUmaGrama = valorPor/gramas # Acha o valor por uma grama do mercado atual
    if valorPorUmaGrama < menorValorPorGrama: #Acha o menor valor por 1 grama
        menorValorPorGrama = valorPorUmaGrama
print("{:.2f}".format(menorValorPorGrama * 1000)) #Acha o menor valor por 1kg
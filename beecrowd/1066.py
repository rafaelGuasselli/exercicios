totalPares = 0
totalImpares = 0
totalPositivos = 0
totalNegativos = 0

for i in range(0, 5):
    num = int(input())
    if num % 2 == 0:
        totalPares += 1
    else:
        totalImpares += 1

    if num > 0:
        totalPositivos += 1
    
    if num < 0:
        totalNegativos += 1
        

print("{:n} valor(es) par(es)".format(totalPares))
print("{:n} valor(es) impar(es)".format(totalImpares))
print("{:n} valor(es) positivo(s)".format(totalPositivos))
print("{:n} valor(es) negativo(s)".format(totalNegativos))
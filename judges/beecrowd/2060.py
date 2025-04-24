qtdNumeros = int(input())
divisores = [2, 3, 4, 5]
total = [0] * 6
numeros = list(map(int, input().split()))

for numero in numeros:
    for divisor in divisores:
        if numero % divisor == 0: 
            total[divisor] += 1

for divisor in divisores:
    print("{:n} Multiplo(s) de {:n}".format(total[divisor], divisor))
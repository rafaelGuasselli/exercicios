totalNumPositivos = 0
somaPositivos = 0
for i in range(0, 6):
    num = float(input())
    if num > 0:
        totalNumPositivos += 1
        somaPositivos += num
print("{:n} valores positivos".format(totalNumPositivos))
print("{:.1f}".format(somaPositivos/totalNumPositivos))
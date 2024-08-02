totalNumPositivos = 0
for i in range(0, 6):
    num = float(input())
    if num > 0:
        totalNumPositivos += 1
print("{:n} valores positivos".format(totalNumPositivos))
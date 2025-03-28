totalPares = 0

for i in range(0, 5):
    num = int(input())
    if num % 2 == 0:
        totalPares += 1
print("{:n} valores pares".format(totalPares))
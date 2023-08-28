entrada = input()
index = 1
while entrada != "0":
    n = int(entrada)
    print("Teste {:n}".format(index))
    
    diferenca = 0
    for i in range(0, n):
        j,z = map(int, input().split())
        diferenca = diferenca + (j - z)
        print(diferenca)
    print("")

    index += 1
    entrada = input()
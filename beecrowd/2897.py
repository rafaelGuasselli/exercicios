def ex2897(entrada):
    numeroDeComandos = int(entrada)
    comandos = list(map(int, input().split()))
    stack = []
    total = 0
    for i in range(0, numeroDeComandos):
        if comandos[i] in stack:
            total += stack.index(comandos[i]) + 1
            stack.insert(0, comandos[i])    
        else:
            total += comandos[i] + i
            stack.insert(0, comandos[i])
    print(total)

while True:
    entrada = input()
    if entrada == "0":
        break
    ex2897(entrada)
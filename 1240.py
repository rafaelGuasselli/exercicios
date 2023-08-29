numeroDeCasosDeTeste = int(input())
for i in range(0, numeroDeCasosDeTeste):
    a, b = input().split()
    encaixa = True
    for i in range(1, len(a) + 1):
        if len(a) < len(b):
            encaixa = False
            break
        
        if i > len(b):
            break

        if a[-i] != b[-i]:
            encaixa = False
            break
    print("encaixa" if encaixa else "nao encaixa")
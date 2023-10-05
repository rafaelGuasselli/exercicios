operacao = input()
soma = 0
for l in range(0, 12):
    for c in range(0, 12):
        num = float(input())
        if (c > l) and (c < (11-l)):
            soma += num 
if operacao == "M":
    soma /= 30
print("{:.1f}".format(soma))
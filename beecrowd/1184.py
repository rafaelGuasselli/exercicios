operacao = input()
soma = 0
for l in range(0, 12):
    for c in range(0, 12):
        num = float(input())
        if l > c:
            soma += num 
if operacao == "M":
    soma /= 66
print("{:.1f}".format(soma))
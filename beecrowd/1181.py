linha = int(input())
operacao = input()
soma = 0
for l in range(0, 12):
    for c in range(0, 12):
        num = float(input())
        if l == linha:
            soma += num 
if operacao == "M":
    soma /= 12
print("{:.1f}".format(soma))
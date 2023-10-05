operacao = input()
soma = 0
for l in range(0, 12):
    for c in range(0, 12):
        num = float(input())
        limite = 12 - c
        if l >= limite and l < (12-limite):
            soma += num 
if operacao == "M":
    soma /= 30
print("{:.1f}".format(soma))
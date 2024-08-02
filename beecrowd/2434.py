numeroDeIteracoes, saldo = map(int, input().split())
menorSaldo = 1000000000
for i in range(0, numeroDeIteracoes):
    movimentacao = int(input())
    saldo += movimentacao
    if saldo < menorSaldo:
        menorSaldo = saldo
print(menorSaldo)
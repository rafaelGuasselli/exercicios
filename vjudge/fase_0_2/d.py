n = int(input())
questoes = [int(e) for e in input().split()]
valores = [int(e) for e in input().split()]


for e in range(1, len(valores)):
    questoes[e] = questoes[e]+questoes[e-1]

menor = float('inf')
for e in range(1, len(valores)):
    valores[e] = valores[e]+valores[e-1]
    if(valores[e]//questoes[e]<menor):
        menor = valores[e]//questoes[e]
print(min(menor,valores[0]//questoes[0] ))   
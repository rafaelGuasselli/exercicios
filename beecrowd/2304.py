qtdDinheiro, totalAcoes = map(int, input().split())

mapaD = {
    "D": qtdDinheiro,
    "E": qtdDinheiro,
    "F": qtdDinheiro,
}

for i in range(0, totalAcoes):
    acao = input().split()

    if acao[0] == "C":
        mapaD[acao[1]] -= int(acao[2])
    
    if acao[0] == "V":
        mapaD[acao[1]] += int(acao[2])
    
    if acao[0] == "A":
        mapaD[acao[1]] += int(acao[3])
        mapaD[acao[2]] -= int(acao[3])
print("{:n} {:n} {:n}".format(mapaD["D"], mapaD["E"], mapaD["F"]))
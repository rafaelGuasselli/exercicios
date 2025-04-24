x = int(input())
y = int(input())

def somaDosImpares(x, y):    
    if x == y: return 0
    
    menorImpar = min(x, y) + (1 + min(x, y) % 2)
    maiorImpar = max(x, y) - (1 + max(x, y) % 2)
    tamanhoDoRange = ((maiorImpar - menorImpar)/2) + 1
    return (menorImpar + maiorImpar) * tamanhoDoRange/2

print("{:.0f}".format(somaDosImpares(x, y)))
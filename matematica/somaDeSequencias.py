x = int(input())
y = int(input())

def somaSequencia(x, y):    
    if x == y: return 0
    
    menor = min(x, y)
    maior = max(x, y)
    tamanhoDoRange = (maior - menor  + 1)/2
    return (menor + maior) * tamanhoDoRange

def somaDosImparesComAsPontas(x, y):    
    if x == y: return 0
    
    menorImpar = min(x, y) + (1 - min(x, y) % 2)
    maiorImpar = max(x, y) - (1 - max(x, y) % 2)
    tamanhoDoRange = ((maiorImpar - menorImpar)/2) + 1
    return (menorImpar + maiorImpar) * tamanhoDoRange/2

def somaDosImparesSemAsPontas(x, y):    
    if x == y: return 0
    
    menorImpar = min(x, y) + (1 + min(x, y) % 2)
    maiorImpar = max(x, y) - (1 + max(x, y) % 2)
    tamanhoDoRange = ((maiorImpar - menorImpar)/2) + 1
    return (menorImpar + maiorImpar) * tamanhoDoRange/2
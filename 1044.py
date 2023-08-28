
def areTheseMultiples(a, b):
    return (a % b == 0) or (b % a == 0) 

a, b = map(lambda a: int(a), input().split())

if areTheseMultiples(a, b):
    print("Sao Multiplos")
else: 
    print("Nao sao Multiplos")

from functools import reduce
numParticipantes = int(input())
satisfacaoParticipantes = map(int, input().split())
soma = reduce(lambda a, b: a + b, satisfacaoParticipantes, 0)
if soma < (numParticipantes/2):
    print("Y")
else:
    print("N")
dimensoesColchao = list(map(lambda a: int(a), input().split()))
dimensoesPorta = list(map(lambda a: int(a), input().split()))

dimensoesColchao.sort()
dimensoesPorta.sort()

passaPelaPorta = dimensoesColchao[0] <= dimensoesPorta[0] and dimensoesColchao[1] <= dimensoesPorta[1]
print("S" if passaPelaPorta else "N")
def ex(entrada):
    numComprimentos = int(entrada)
    totalVaretas = 0
    for i in range(0, numComprimentos): 
        comprimento, numVaretas = map(int, input().split())
        totalVaretas += (numVaretas - numVaretas % 2)
    print(totalVaretas // 4)

while True:
    entrada = input()
    if entrada == "0":
        break
    ex(entrada)
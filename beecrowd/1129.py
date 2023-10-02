converter = ["A", "B", "C", "D", "E"]

def ex(entrada):
    numTestes = int(entrada)
    for i in range(0, numTestes):
        medias = list(map(int, input().split()))
        qtdMarcadas = 0
        indexMarcada = 0
        for j in range(0, 5):
            if medias[j] <= 127:
                qtdMarcadas += 1
                indexMarcada = j
        
        if qtdMarcadas > 1 or qtdMarcadas == 0:
            print("*")
        else: 
            print(converter[indexMarcada])


while True:
    entrada = input()
    if entrada == "0":
        break
    ex(entrada)
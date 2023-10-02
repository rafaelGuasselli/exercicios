def eUmPico(m1, m2, m3):    
    return (m2 > m1 and m2 > m3) or (m2 < m1 and m2 < m3)

def ex(entrada):
    numDeMedidas = int(entrada)
    medidas = list(map(int, input().split()))
    cout = 0
    for i in range(0, numDeMedidas):
        if (eUmPico(medidas[i-1], medidas[i], medidas[(i+1) % numDeMedidas])):
            cout += 1
    print(cout)

while True:
    entrada = input()
    if (entrada == "0"):
        break
    ex(entrada)
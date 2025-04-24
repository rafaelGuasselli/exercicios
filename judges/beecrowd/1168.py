QTD_LEDS = {
    "1": 2,
    "2": 5,
    "3": 5, 
    "4": 4,
    "5": 5,
    "6": 6,
    "7": 3,
    "8": 7,
    "9": 6,
    "0": 6
}

qtdCasosDeTeste = int(input())

for i in range(0, qtdCasosDeTeste):
    numero = input()
    totalDeLeds = 0
    for j in range(0, len(numero)):
        totalDeLeds += QTD_LEDS[numero[j]]
    print("{:n} leds".format(totalDeLeds))
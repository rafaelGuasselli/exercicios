def converterHexPraDec(hex):
    mapa = {
        "0": 0,
        "1": 1,
        "2": 2,
        "3": 3,
        "4": 4,
        "5": 5,
        "6": 6,
        "7": 7,
        "8": 8,
        "9": 9,
        "A": 10,
        "B": 11,
        "C": 12,
        "D": 13,
        "E": 14,
        "F": 15,
    }

    dec = 0
    dec += 16 * mapa[hex[0]]
    dec += 1 * mapa[hex[1]]
    return dec

qtdChars = int(input())
hexes = input().split()
frase = ""

for hex in hexes:
    dec = converterHexPraDec(hex)
    frase += chr(dec)

print(frase)
from math import floor
def ex(entrada):
    frase = (''.join(x for x in entrada if x.isalpha())).lower()
    
    for i in range(floor(len(frase)/2)):
        if frase[i] != frase[-(i+1)]:
            print("Uh oh..")
            return
    print("You won't be eaten!")

while True:
    entrada = input()
    if entrada == "DONE":
        break
    ex(entrada)
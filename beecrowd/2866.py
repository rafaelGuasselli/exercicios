def ex():
    palavraCifrada = input()
    palavraDecifrada = ""
    for letra in palavraCifrada:
        if letra.islower():
            palavraDecifrada += letra
    
    print(palavraDecifrada[::-1])

numCasosTeste = int(input())
for i in range(0, numCasosTeste):
    ex()
def ex(entrada):
    numVoluntariosMergulharam, numVoltaram = map(int, entrada.split())
    arrayDosQueVoltaram = list(map(int, input().split()))
    arrayDosQueNãoVoltaram = []

    nenhum = True
    for i in range(1, numVoluntariosMergulharam + 1):
        if not i in arrayDosQueVoltaram:
            nenhum = False
            print(i, end=" ")
    if nenhum:
        print("*")
    else:
        print()

while True:
    try:
        entrada = input()
        ex(entrada)
    except EOFError:
        break
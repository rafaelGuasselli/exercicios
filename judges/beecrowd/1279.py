def ex1279(entrada):
    ano = int(entrada)
    divisivelPor4 = ano % 4 == 0
    divisivelPor15 = ano % 15 == 0
    divisivelPor55 = ano % 55 == 0
    divisivelPor100 = ano % 100 == 0
    divisivelPor400 = ano % 400 == 0
    

    anoBissesto = (divisivelPor4 and not divisivelPor100) or divisivelPor400
    festivalHuluculu = divisivelPor15
    festivalBulukulu = anoBissesto and divisivelPor55
    anoNormal = not (anoBissesto or festivalBulukulu or festivalHuluculu)

    if anoBissesto:
        print("This is leap year.")
    if festivalHuluculu:
        print("This is huluculu festival year.")
    if festivalBulukulu:
        print("This is bulukulu festival year.") 
    if anoNormal:
        print("This is an ordinary year.")
pula = 0
while (True):
    try:
        entrada = input()
        if pula:
            print('')
        pula = 1
        ex1279(entrada)
    except EOFError:
        break
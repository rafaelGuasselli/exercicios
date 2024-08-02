fraseCifrada = input().split()
fraseDecifrada = ""

for palavra in fraseCifrada:
    for i in range(0, len(palavra)):
        if i % 2 != 0:
            fraseDecifrada += palavra[i]
    fraseDecifrada += " "

print(fraseDecifrada[:-1])
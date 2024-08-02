a, b, c = map(float, input().split())
tempo = [(a, "Otavio"), (b, "Bruno"), (c, "Ian")]
tempo.sort()

if tempo[0][0] == tempo[1][0]:
    print("Empate")
else:
    print(tempo[0][1])
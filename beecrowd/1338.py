numeroJogadores, numeroPartidas = map(int, input().split())
total = 0
for i in range(0, numeroJogadores):
    desenpenhoJogador = list(map(int, input().split()))
    for j in range(0, numeroPartidas):
        if desenpenhoJogador[j] == 0:
            break
        if j == numeroPartidas - 1:
            total += 1
print(total)
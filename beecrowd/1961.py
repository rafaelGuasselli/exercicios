alturaPulo, qtdCanos = map(int, input().split())
canos = list(map(int, input().split()))

vitoria = True
anterior = canos[0]
for i in range(1, qtdCanos):
    if abs(canos[i] - anterior) > alturaPulo:
        vitoria = False
        break
    anterior = canos[i]
if vitoria:
    print("YOU WIN")
else:
    print("GAME OVER")
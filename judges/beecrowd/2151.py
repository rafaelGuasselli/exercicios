def ex():
    alturaParede, larguraParede, socoY, socoX = map(int, input().split())
    socoY -= 1
    socoX -= 1

    parede = []
    for l in range(0, alturaParede):
        linha = list(map(int, input().split()))
        parede.append(linha)

    for l in range(0, alturaParede):
        for c in range(0, larguraParede):
            impacto = parede[l][c]
            impacto += max(10 - max(abs(socoX - c), abs(socoY - l)), 1)
            print(impacto, end=" " if c < larguraParede-1 else "")
        print()

numeroTestes = int(input())
for i in range(0, numeroTestes):
    print("Parede {:n}:".format(i+1))
    ex()

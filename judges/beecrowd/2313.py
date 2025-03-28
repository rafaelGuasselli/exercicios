sides = list(map(lambda a: int(a), input().split()))
sides.sort(reverse=True)
a, b, c = sides

canFormTriangle = (a + b) > c and (a + c) > b and (b + c) > a
if canFormTriangle:
    isScalene = a != b and a != c and b != c
    isEquilateral = a == b and b == c
    isIsoceles = not isEquilateral and not isScalene
    isRectangle = a ** 2 == (b ** 2 + c ** 2)

    if isEquilateral:
        print("Valido-Equilatero")
    if isScalene:
        print("Valido-Escaleno")
    if isIsoceles:
        print("Valido-Isoceles")
    print("Retangulo: {}".format("S" if isRectangle else "N"))
else:
    print("Invalido")
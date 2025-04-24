while True:
    coordinates = map(int, input().split())
    x1, y1, x2, y2 = coordinates
    if (x1 + x2 + y1 + y2) == 0:
        break

    sameHorizontal = x1 == x2
    sameVertical = y1 == y2
    sameDiagonal = abs(y2 - y1) == abs(x2 - x1)
    samePoint = sameHorizontal and sameVertical

    if samePoint:
        print("0")
    elif sameHorizontal or sameVertical or sameDiagonal:
        print("1")
    else:
        print("2")

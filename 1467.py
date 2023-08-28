while True:
    try:
        a, b, c = input().split()

        aliceGanhou = a != b and a != c
        betoGanhou = b != a and b != c
        claraGanhou = c != a and c != b

        if aliceGanhou:
            print("A")
        elif betoGanhou:
            print("B")
        elif claraGanhou:
            print("C")
        else:
            print("*")
    except EOFError:
        break
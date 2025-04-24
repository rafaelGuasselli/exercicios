def ex():
    plug1 = input().split()
    plug2 = input().split()

    for i in range(0, 5):
        if plug1[i] == plug2[i]:
            print("N")
            return
    print("Y")
ex()
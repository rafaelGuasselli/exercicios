n = int(input())
for i in range(0, n):
    x = int(input())
    prime = True

    j = 2
    while j * j < x: 
        if x % j == 0:
            print("Not Prime")
            prime = False
            break
        j+=1
    if prime:
        print("Prime")
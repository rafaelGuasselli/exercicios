from math import ceil
t = int(input())
while t:
    t-=1
    n = int(input())
    a = list(map(int, list(input())))
    b = list(map(int, list(input())))

    par = [0] * n
    impar = [0] * n

    for i in range(n):
        par[i] = a[i] if i%2 == 0 else b[i]
        impar[i] = a[i] if i%2 == 1 else b[i]
    
    count1 = 0
    count2 = 0
    for i in range(0, n):
        count1 += par[i]
        count2 += impar[i]

    print("NO" if (count1 > n/2 or count2 > ceil(n/2)) else "YES")
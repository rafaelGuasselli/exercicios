t=int(input())
while t:
    t-=1
    n=int(input())
    a=list(map(int, input().split()))
    b=list(map(int, input().split()))
    
    xa=0
    xb=0
    for i in range(n):
        xa ^= a[i]
        xb ^= b[i]
        
    if xa == xb:
        print("Tie")
    else:
        lastInd=-1
        for i in range(n):
            if a[i] != b[i]:
                lastInd=i
        if lastInd == -1:
            print("Tie")
        elif lastInd%2 == 0:
            print("Ajisai")
        else:
            print("Mai")
        
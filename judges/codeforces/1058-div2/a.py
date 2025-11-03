t=int(input())
while t:
    t-=1
    n=int(input())
    a=list(map(int,input().split()))
    
    mex = [0]*200
    for i in a:
        mex[i]=1
        
    for i in range(0, 101):
        if mex[i] == 0:
            print(i)
            break
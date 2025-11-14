t=int(input())
while t:
    t-=1
    x,y=map(int, input().split())
    
    if x < y:
        print(2)
    elif x>=y+2 and y > 1:
        print(3)
    else:
        print(-1)
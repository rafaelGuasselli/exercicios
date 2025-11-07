t=int(input())
while t:
    t-=1
    n=int(input())
    a=list(map(int, input().split()))
    x=int(input())
    
    if min(a)<=x<=max(a):
        print("Yes")
    else: 
        print("No")
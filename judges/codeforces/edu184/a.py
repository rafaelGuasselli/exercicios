t=int(input())
while t:
    t-=1
    n, a = map(int, input().split())
    v=list(map(int, input().split()))
    
    u=[i for i in v if i > a]
    d=[i for i in v if i < a]
    
    if len(u) > len(d):
        print(a+1)
    else:
        print(a-1)
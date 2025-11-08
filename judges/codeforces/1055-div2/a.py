t=int(input())
while t:
    t-=1
    n=int(input())
    a=set(map(int, input().split()))
    print(len(a)*2-1)
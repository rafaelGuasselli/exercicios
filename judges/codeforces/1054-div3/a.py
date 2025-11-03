t=int(input())
while t:
    t-=1
    n = int(input())
    a = list(map(int, input().split()))
    
    count = 1 * a.count(0) + 2 * (a.count(-1)%2)
    
    print(count)
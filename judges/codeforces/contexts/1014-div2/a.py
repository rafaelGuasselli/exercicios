t = int(input())
while t:
    t-=1
    n = int(input())
    a = list(map(int, input().split()))
    a.sort()
    print(a[-1]-a[0])
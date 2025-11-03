t=int(input())
while t:
    t-=1
    a,b,c,d = map(int, input().split())
    s = [a, b, c, d]
    s.sort()
    if s[0] == s[1] == s[2] == s[3]:
        print("Yes")
    else:
        print("No")
        
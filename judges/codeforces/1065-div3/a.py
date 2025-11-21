t=int(input())
while t:
    t-=1
    n=int(input())
    if n%2:
        print(0)
    else:
        cows = n//4
        print(cows+1)
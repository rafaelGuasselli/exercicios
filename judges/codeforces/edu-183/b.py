t=int(input())
while t:
    t-=1
    n, k = map(int, input().split())
    s=input()
    top=[0,0]
    bottom=[0,0]
    
    for i in s:
        if i == "0":
            top[0] += 1
            top[1] += 1
        elif i == "1":
            bottom[0] += 1
            bottom[1] += 1
        else:
            top[1] += 1
            bottom[1] += 1
    
    
    for i in range(n):
        if i < top[0] or i > n-bottom[0]-1 or k >= n:
            print("-",end="")
        elif i < top[1] or i > n-bottom[1]-1:
            print("?",end="")
        else:
            print("+",end="")
    print()
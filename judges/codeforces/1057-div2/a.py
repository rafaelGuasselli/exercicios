t=int(input())
while t:
    t-=1
    n=int(input())
    a=list(map(int, input().split()))
    a.sort()
    
    prev=0
    count=0
    for i in range(n): 
        if a[i] != prev:
            count+=1
        prev=a[i]
    
    print(count)
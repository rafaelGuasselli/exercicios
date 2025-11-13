t=int(input())
while t:
    t-=1
    n=int(input())
    s=input()
    
    count=int(s[0]=="1")
    prev=s[0]
    for i in s:
        if i != prev:
            count+=1
        prev=i
    print(count)
t = int(input())
while t:
    t-=1
    n=int(input())
    s=input().split()
    
    freqA = [0] * 30
    freqB = [0] * 30
    
    for i in s[0]:	
        freqA[ord(i)-ord("a")] += 1
    
    for i in s[1]:
        freqB[ord(i)-ord("a")] += 1
    
    yes = True
    for i in range(30):
        if freqB[i] != freqA[i]:
            yes = False
            
    print("Yes" if yes else "No")
    
t = int(input())
while t:
    t-=1
    n = int(input())
    a = list(map(int, input().split()))

    impar = []
    par = []

    for i in a:        
        if i%2:
            impar.append(i)
        else:
            par.append(i)
    
    impar.sort()
    par.sort()

    if len(impar) == 0:
        print(par[-1])
    elif len(par) == 0:
        print(impar[-1])
    else:
        print(sum(a)-len(impar)+1)

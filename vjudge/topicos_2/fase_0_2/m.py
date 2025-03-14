n, v = map(int, input().split())
P = 0
N = 0
ps = v*0.75
ns = v*0.25
t = 0
for _ in range(n):
    a, b = input().split()
    if(a == 'P'):
        P+=int(b)
    else:
        N+=int(b)
while(N!=0 or P!=0):
    if(N==0 or P==0):
        if N==0:
            t += P/v
            P = 0
        else:
            t += N/v
            N = 0
    else:
        if (P/ps)<(N/ns):
            t += P/ps
            N -= (P/ps)*ns
            P = 0
        else:
            t += N/ns
            P -= (N/ns)*ps
            N = 0
print(f'{t:.10f}')
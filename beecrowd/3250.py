a, b = input().split()
a = int(a)
b = int(b)
D = {}
for i in range(a):
    D[i] = 0
for _ in range(b):
    x, y = input().split()
    x = int(x)
    y = int(y)
    D[x] += 1
    D[y] += 1
rambo = True
for e in D:
    if (D[e])%2!=0:
        rambo = False
if rambo:
    print("Rambo esta salvo")
else:
    print("Rambo esta perdido")
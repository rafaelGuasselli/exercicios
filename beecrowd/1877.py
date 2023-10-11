numeroTorres, k = map(int, input().split())
torres = list(map(int, input().split()))

picos = vales = 0

for i in range(1, numeroTorres-1):
    anterior = torres[i-1] 
    proximo = torres[i+1]
    atual = torres[i]

    if atual > anterior and atual > proximo:
        picos += 1
    elif atual < anterior and atual < proximo:
        vales += 1

if picos == vales+1 == k:
    print("beautiful")
else:
    print("ugly")

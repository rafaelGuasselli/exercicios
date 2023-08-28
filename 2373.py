n = int(input())
totalDeCoposQuebrados = 0
for i in range(0, n):
    l, c = map(int, input().split())
    if (l > c):
        totalDeCoposQuebrados += c
print(totalDeCoposQuebrados)
n, m, k = map(int, input().split())

solve = [[0 for i in range(m)] for j in range(n)]
count = [0]*n
total = []
for i in range(k):
	u, p = map(int, input().split())
	u-=1
	p-=1
	if not solve[u][p]:
		count[u] += 1
	solve[u][p] = 1
	if count[u] == m:
		total.append(u)

for i in total:
	print(i+1, end=" ")
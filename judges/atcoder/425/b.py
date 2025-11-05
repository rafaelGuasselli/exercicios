n = int(input())
l = list(map(int, input().split()))

p = [i for i in l]
remaining = set(range(1, n+1))

possivel = True
for i in l:
	if i == -1: continue
	if i not in remaining:
		possivel = False
		break
	
	remaining.remove(i)

for i in range(n):
	if p[i] == -1:
		p[i] = remaining.pop()

if possivel:
	print("Yes")
	print(*p)
else:
	print("No")
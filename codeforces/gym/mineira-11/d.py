n, l = map(int, input().split())
x = list(map(int, input().split()))

for i in range(n):
	x[i] = 100-x[i]

x.sort()
count = 0

for i in x:
	if l >= i:
		l -= i
		count+=1
	else:
		break

print(count)
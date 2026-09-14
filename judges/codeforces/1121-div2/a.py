t = int(input())
while t:
	t-=1
	n = int(input())
	l = list(map(int, input().split()))

	ll = []
	for i in range(n):
		if i+1 != l[i]:
			ll.append(l[i])

	possible = True
	for i in range(1, len(ll)):
		if ll[i] >= ll[i-1]:
			possible = False
			break

	print("Yes" if possible else "No")
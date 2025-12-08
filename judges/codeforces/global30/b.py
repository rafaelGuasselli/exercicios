t=int(input())
while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))

	possivel=False
	for i in range(n):
		for j in range(i+1, n):
			if (a[j]%a[i]) % 2 == 0:
				print(a[i], a[j])
				possivel = True
				break
		if possivel:
			break
	if not possivel:
		print(-1)
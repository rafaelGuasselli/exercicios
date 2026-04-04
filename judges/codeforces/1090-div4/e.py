t=int(input())
while t:
	t-=1
	n = int(input())
	a = list(map(int, input().split()))

	biggest = 0
	for i in range(n):
		for j in range(i+1, n):
			biggest = max(biggest, a[i]^a[j])
			
	print(biggest)
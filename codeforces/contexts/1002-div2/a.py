t = int(input())
while t:
	t-=1
	n = int(input())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))

	mapA = {}
	mapB = {}

	for val in a:
		mapA[val] = 1
	
	for val in b:
		mapB[val] = 1

	if len(mapA)*len(mapB) >= 3:
		print("YES")
	else:
		print("NO")
	
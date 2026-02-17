t = int(input())
while t:
	t-=1
	n = int(input())
	a = list(map(int, input().split()))

	if 67 in a != -1:
		print("Yes")
	else:
		print("No")
t=int(input())
while t:
	t-=1
	n, k = map(int, input().split())
	a = list(map(int, input().split()))
	b = list(map(int, input().split()))

	a = [i%2 for i in a]
	b = [i%2 for i in b]

	ai = a.count(1)
	bi = b.count(1)

	if ai <= bi and k%2==1:
		print("YES")
	elif ai >= bi and k%2==0:
		print("YES")
	else:
		print("NO")
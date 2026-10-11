t=int(input()) 
while t:
	t-=1
	a, b = map(int, input().split())
	if a == b:
		print(a)
	elif b > a+1:
		print(-1)
	else:
		print(a+abs(b-a)%2)
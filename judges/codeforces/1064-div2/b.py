t=int(input())
while t:
	t-=1
	a,b,n=map(int, input().split())
	
	if b >= a:
		print(1)
	elif a/n == b:
		print(1)
	elif n*b <= a:
		print(1)
	else:
		print(2)
	
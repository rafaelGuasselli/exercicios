t=int(input())
while t:
	t-=1
	n=int(input())
	y,r=map(int, input().split())
	r = min(n, r+y//2)
	print(r)
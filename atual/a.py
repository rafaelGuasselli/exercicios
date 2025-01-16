t = int(input())
while t:
	t-=1
	n, m = map(int, input().split())
	print(max(n, m)+1)
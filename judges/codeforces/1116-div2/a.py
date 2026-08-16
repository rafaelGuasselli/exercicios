t = int(input())
while t:
	t-=1
	a, b, c = map(int, input().split())
	l = [a, b, c]
	l.sort()

	aa = abs(l[2]-l[0])
	bb = abs(l[0]+l[1]-l[0])
	cc = abs(l[2]-l[2]-l[1])
	dd = abs(l[0]+l[1]-l[2]-l[1])

	print(min([aa, bb, cc, dd]))

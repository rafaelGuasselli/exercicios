t=int(input())
while t:
	t-=1
	n, h, l = map(int, input().split())
	lista = list(map(int, input().split()))

	a=0
	b=0
	c=0
	for i in lista:
		if i >= 1 and i <= h and i <= l:
			c+=1

		if i >= 1 and i <= h:
			a+=1

		if i >= 1 and i <= l:
			b+=1

	e = min(max(a-c, b-c), c)
	r = min(a-c, b-c)+e+(c-e)//2

	print(r)
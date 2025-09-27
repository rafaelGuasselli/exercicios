n, q = map(int, input().split())
l = list(map(int, input().split()))


preffix = [l[0]] * n
for i in range(1, n):
	preffix[i] = preffix[i-1]+l[i]

pivot = 0
for i in range(q):
	command = list(map(int, input().split()))

	if command[0] == 1:
		c, v = command
		pivot = (pivot+v)%n
	else:
		c, l, r = command
		l += pivot-1
		r += pivot-1

		result = 0
		l %= n
		r %= n
		if r < l:	
			result += preffix[n-1] - (preffix[l-1] if l > 0 else 0)
			result += preffix[r]
		else:
			result += preffix[r]-(preffix[l-1] if l > 0 else 0)
		print(result)
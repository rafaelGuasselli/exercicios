n, m, k = map(int, input().split())


def incRangSum(l, r):
	l = max(l, 0)
	r = max(r, 0)
	return ((r-l+1)/2) * (l+r)


#1 2 3 ... k k+1 ... n 
def check(v):
	t = v+n-1

	qtdBedsRight = (n-k-1)
	qtdBedsLeft = (k-2)

	t += incRangSum(v-2-qtdBedsRight,v-2)
	t += incRangSum(v-2-qtdBedsLeft,v-2)
	return t<=m

left = 0
right = 1e9
maximo = 0

while left <= right:
	mid = left + (right-left)//2
	if check(mid):
		maximo = max(maximo, mid)
		left = mid+1
	else:
		right = mid-1

print(int(maximo))
	
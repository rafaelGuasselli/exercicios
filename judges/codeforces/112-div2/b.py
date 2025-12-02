n, k = map(int, input().split())

def check(v):
	total = 0
	while (v > 0):
		total+=v
		v//=k
	return total


left = 0
right = 1e18
minimo = 1e9

while left <= right:
	mid = left + (right-left)//2
	if check(mid) >= n:
		minimo = min(minimo, mid)
		right = mid-1
	else:
		left = mid+1

print(int(minimo))
	
t = int(input())

while t:
	t-=1
	n, k = map(int, input().split())

	left = 1
	right = 1e18
	nth = 0

	while left <= right:
		mid = left + (right-left)//2
		amounfOfMultiples = mid//n
		val = mid-amounfOfMultiples

		if val == k:
			nth = mid if mid % n else mid-1
			break
		elif val > k:
			right = mid-1
		else:
			left = mid+1

	print(int(nth))
		
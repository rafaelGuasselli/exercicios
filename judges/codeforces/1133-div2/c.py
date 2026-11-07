t=int(input())
while t:
	t-=1
	n = int(input())
	a = list(map(int, input().split()))

	bgap = 0
	ibgap = []
	for i in range(1, n):
		gap = abs(a[i]-a[i-1])
		if gap > bgap:
			bgap = gap
			ibgap = [i]
		elif gap == bgap:
			ibgap.append(i)

	
	prefix = [0] * n
	suffix = [0] * n

	for i in range(1, n):
		prefix[i] = max(prefix[i-1], abs(a[i]-a[i-1]))

	for i in range(n-2, -1, -1):
		suffix[i] = max(suffix[i+1], abs(a[i]-a[i+1]))


	l = ibgap[0]
	smallestBgap = bgap

	rprefix = [0] * n
	rsuffix = [0] * n


	for i in range(l+1, n):
		gap = abs(a[i]-a[i-1])
		rprefix[i] = max(gap, rprefix[i-1])

	for i in range(l-2, -1, -1):
		gap = abs(a[i]-a[i+1])
		rsuffix[i] = max(gap, rsuffix[i+1])	

	for i in range(l, n):
		il = l
		ir = i
		bil = il-1
		air = ir+1

		gapA = abs(a[bil] - 2 * a[ir])
		gapB = 2 * rprefix[ir]
		gapC = suffix[air] if air < n else 0
		gapD = abs(a[air] - 2 * a[il]) if air < n else 0
		gapE = prefix[bil]

		smallestBgap = min(smallestBgap, max([gapA, gapB, gapC, gapD, gapE]))

	for i in range(l-1, -1, -1):
		il = l-1
		ir = i
		bil = il+1
		air = ir-1

		gapA = abs(a[bil] - 2 * a[ir])
		gapB = 2 * rsuffix[ir]
		gapC = prefix[air] if air >= 0  else 0
		gapD = abs(a[air] - 2 * a[il]) if air >=0 else 0
		gapE = suffix[bil]

		smallestBgap = min(smallestBgap, max([gapA, gapB, gapC, gapD, gapE]))

	print(smallestBgap)
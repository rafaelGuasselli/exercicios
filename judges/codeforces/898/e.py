t=int(input())

def test(a, h, x):
	totalWater=0
	for i in a:
		totalWater+=max(0, h-i)
	return totalWater<=x

while t:
	t-=1
	n, x = map(int, input().split())
	a = list(map(int, input().split()))


	l=0
	r=1e18+10
	h=0
	while l<=r:
		mid=l+(r-l)//2

		if test(a, mid, x):
			h=max(mid, h)
			l = mid+1
		else:
			r = mid-1
	
	print(int(h))

n, k = map(int, input().split())
a=list(map(int,input().split()))

a.sort()
costPerIncrease=1
for i in range(n//2, n-1):
	if (a[i+1]-a[i]) * costPerIncrease <= k:
		k-= (a[i+1]-a[i]) * costPerIncrease
		costPerIncrease+=1

if k == 0:
	print(a[n//2+costPerIncrease-1])
else:
	a[-1] += k/costPerIncrease
	print(int(a[-1]))
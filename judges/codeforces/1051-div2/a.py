t=int(input())
while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))
	passa=True
	ind=0
	
	while ind+1 < n and a[ind]<a[ind+1]:
		ind+=1

	while ind+1 < n and a[ind]>a[ind+1]:
		ind+=1
	
	

	print("YES" if ind==n-1 else "NO")
	
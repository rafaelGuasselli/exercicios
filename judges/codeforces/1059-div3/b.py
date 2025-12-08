t=int(input())
while t:
	t-=1
	n=int(input())
	a=input()
	
	ind=[]
	for i in range(n):
		if a[i] == "0":
			ind.append(i+1)
	
	print(len(ind))
	print(*ind)
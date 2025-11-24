t=int(input())
while t:
	t-=1
	n=int(input())
	c=list(map(int, input().split()))
	d=list(map(int, input().split()))
	
	a=[0]*n
	b=[0]*n
	for i in range(32, -1, -1):
		xc=0
		xd=0
		for j in range(n):
			xc^=(c[j]&1<<i)>0
			xd^=(d[j]&1<<i)>0
	
		if xc != xd:
			for j in range(n):
				a[j]=(c[j]&1<<i)>0
				b[j]=(d[j]&1<<i)>0
			break
	
	xa=0
	xb=0
	for i in range(n):
		xa ^= a[i]
		xb ^= b[i]
		
	if xa == xb:
		print("Tie")
	else:
		lastInd=-1
		for i in range(n):
			if a[i] != b[i]:
				lastInd=i
		if lastInd == -1:
			print("Tie")
		elif lastInd%2 == 0:
			print("Ajisai")
		else:
			print("Mai")
		
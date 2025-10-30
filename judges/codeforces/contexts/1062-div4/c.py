t=int(input())
while t:
	t-=1
	n=int(input())
	s=list(map(int, input().split()))

	temPar=0
	temImpar=0

	for i in s:
		if i%2: temImpar=1
		else: temPar=1

	if temImpar and temPar:
		s.sort()
	
	print(*s)
	
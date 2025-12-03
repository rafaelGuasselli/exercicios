t=int(input())
 
 
 
while t:
	t-=1
	n=int(input())
	b=list(map(int, input().split()))
	b.sort()
 
	limiteMaximo=0
	for i in b:
		limiteMaximo+=i>0
	
	#count limite superior
	limite2 = sum(b)-n+1
	print(min(limite2, limiteMaximo))
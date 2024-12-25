t = int(input())
 
while t:
	t-=1
 
	n = int(input())
	lista = list(map(int, input().split()))
	left = 0
	right = n-1
	
	orderedLista = []
	for i in range(n):
		orderedLista.append((lista[i], i))
	orderedLista.sort()
 
 
	l = orderedLista[0][1]
	r = orderedLista[0][1]
 
	for i in range(n):
		if (orderedLista[i][1] < l or orderedLista[i][1] > r):
			if abs(l - orderedLista[i][1])+(r-l)+1 > orderedLista[i][0] and abs(r - orderedLista[i][1])+(r-l)+1 > orderedLista[i][0]:
				left = 1e9
				break
 
		l = min(l, orderedLista[i][1])
		r = max(r, orderedLista[i][1])
	
		
	for i in range(n):
		a = lista[i]
		left = max(left, i-a+1)
		right = min(right, a+i-1)
 
	if (right >= left):    
		print(right-left+1)
	else:
		print(0)
t=int(input())
while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))

	maior=0
	count=0
	for i in a:
		if i >= maior:
			maior = i
		else:
			count+=1

	print(count)
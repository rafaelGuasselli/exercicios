t=int(input())

def smallestOdd(le, lo, k):
	res = k-le
	return min(max(min(res+(1-res%2), lo-(1-lo%2)), max(res, 1)), k)


while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))

	odd=[]
	even=[]
	for i in a:
		if i%2:
			odd.append(i)
		else:
			even.append(i)
	
	odd.sort()
	even.sort()


	sufixEven = [0] * (len(even)+1)
	if len(even) > 0:
		sufixEven[-1] = even[-1]

	for i in range(1, len(sufixEven)-1):
		sufixEven[-i-1] = sufixEven[-i]+even[-i-1]

	for k in range(1, n+1):
		total=0
		if len(odd) == 0:
			print(0, end=" ")
			continue

		so = smallestOdd(len(even), len(odd), k)
		if so%2:
			total+=odd[-1]+sufixEven[-(k-so)]
		print(total, end=" ")
	print()
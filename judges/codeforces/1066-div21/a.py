t=int(input())
while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))
	freq=[0]*(n+1)
	for i in a:
		freq[i] += 1
	
	count=0
	for i in range(0,n+1):
		count+=(freq[i]-i) if freq[i] >= i else freq[i]
		
	print(count)
		
t=int(input())

def incRangeSum(l, r):
	return ((r-l+1)*(r+l))//2

while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))
	freq=[0]*(2*n+1)

	for i in range(n):
		freq[a[i]-i+n]+=1

	total=0
	for i in range(2*n+1):
		total += incRangeSum(1, freq[i]-1) if  freq[i] > 1 else 0

	print(total)
t=int(input())
mod=int(1e9+7)
while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))

	suffix = [a[-1]]*n
	for i in range(1, n):
		suffix[-i-1] = suffix[-i]+a[-i-1]
	
	total = 0
	q = (n * (n - 1))//2
	qm1 = pow(q, mod-2, mod)
	
	for i in range(n-1):
		total = (total+suffix[i+1]*a[i])%mod

	total = (total*qm1)%mod
	print(total)
t=int(input())
primes = [1]
isPrime = [1] * 1000000

for i in range(2, 1000000):
	if isPrime[i]:
		primes.append(i)
		for j in range(i*i, 1000000, i):
			isPrime[j] = 0



while t:
	t-=1
	n = int(input())
	r=[]

	for i in range(n):
		r.append(primes[i] * primes[i+1])
	print(*r)

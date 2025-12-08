t=int(input())
 
mod = 1000003
maxVal = mod

fact = [1] * maxVal
invFact = [1] * maxVal

for i in range(2, maxVal):
	fact[i] = (fact[i-1] * i) % mod

invFact[maxVal-1] = pow(fact[maxVal-1], mod - 2, mod)
for i in range(maxVal-2, -1, -1):
	invFact[i] = (invFact[i+1] * (i + 1)) % mod

 
while t:
	t-=1
	n=int(input())
	a=list(map(int, input().split()))
	b=list(map(int, input().split()))
	
	min2x = 1e9
	for i in range(n):
		count=0
		while pow(2, count+1) * a[i] <= b[i]:
			count+=1
		
		min2x = min(min2x, count)
	
	totalMoves = min2x
	for i in range(n):
		a[i] *= pow(2, min2x)
	
	
	level = [[] for i in range(min2x+1)]
	for i in range(n):
		diff=b[i]-a[i]
		for j in range(min2x, 0, -1):
			step = (1<<j)

			if diff >= step:
				count=diff//(1<<j)
				level[j].append(count)
				totalMoves += count
				diff -= count*step
 
		if diff > 0:
			totalMoves += diff
			level[0].append(diff)
 
	totalAmountOfPermutations=1
	for i in range(min2x, -1, -1):
		current = 0 if sum(level[i]) >=mod else fact[sum(level[i])]
		for j in level[i]:
			current*=invFact[j]
		totalAmountOfPermutations = (totalAmountOfPermutations * current) % mod
 
 
	print(totalMoves, totalAmountOfPermutations)
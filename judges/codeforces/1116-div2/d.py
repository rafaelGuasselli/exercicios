from math import ceil, floor 
size = int(1e6+10)
mod = 998244353
fac = [1] * size
inv = [1] * size

for i in range(2, size):
	fac[i] = (fac[i-1]*i)%mod

inv[size-1] = pow(fac[size-1], mod-2, mod)
for i in range(size-2, 1, -1):
	inv[i] = (inv[i+1] * (i+1))%mod



t = int(input())
while t:
	t-=1
	n = int(input())
	s = input()

	runs = []
	count = 1

	for i in range(1, len(s)):
		if s[i] != s[i-1]:
			runs.append(count)
			count = 0
		count+=1

	if count: runs.append(count)

	r0 = ceil(len(runs)/2) 
	e0 = sum(runs[0::2])-r0
	r1 = floor(len(runs)/2) 
	e1 = sum(runs[1::2])-r1

	t11 = fac[(r0-1)+e0]
	t12 = (inv[r0-1]*inv[e0])%mod
	t13 = (t11*t12)%mod

	t21 = fac[(r1-1)+e1]
	t22 = (inv[r1-1]*inv[e1])%mod
	t23 = (t21*t22)%mod

	total = (t13*t23)%mod

	print(total)
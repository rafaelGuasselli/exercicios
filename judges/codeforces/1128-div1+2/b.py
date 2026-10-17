t = int(input())
while t:
	t-=1
	n = int(input())
	a = list(map(int,input().split()))

	if n == 1:
		print(a[0])
	else:
		prefix = [0]*n
		suffix = [0]*n

		prefix[0] = a[0]
		for i in range(1, n):
			prefix[i] = max(prefix[i-1]-1, a[i])

		suffix[-1] = a[-1]
		for i in range(n-2, -1, -1):
			suffix[i] = max(suffix[i+1]-1, a[i])

		delicacy = 0
		for i in a:
			delicacy |= i

		for i in range(0, 64):
			if delicacy&(1<<i):
				continue

			for j in range(n):
				target = 2**i
				current = a[j]%target
				diff = abs(a[j]-max(prefix[j], suffix[j]))
				if diff >= target-current:
					delicacy |= target
					break

		print(delicacy)
		
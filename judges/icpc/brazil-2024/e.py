n = int(input())
a = list(map(int, input().split()))

if a.count(0) == n:
	print(*list(range(n, 0, -1)))
else:
	usado = [0 for i in range(0, n+1)]

	valLeft = [0] * (n+1)
	valRight = [0] * (n+1)
	distLeft = [0] * (n+1)
	distRight = [0] * (n+1)

	lastPos = 0
	lastValue = -1
	for i in range(n):
		if a[i] == 0:
			distRight[i] = i-lastPos
			valRight[i] = lastValue
		else:
			lastValue = a[i]
			lastPos = i

	lastPos = n-1
	lastValue = -1
	for i in range(n-1, -1, -1):	
		if a[i] == 0:
			distLeft[i] = lastPos-i
			valLeft[i] = lastValue
		else:
			lastValue = a[i]
			lastPos = i


	left = 0
	right = n-1
	proximo = 1
	possivel = True


	while left <= right:
		if a[left] == proximo:
			left += 1
		elif a[right] == proximo:
			right -= 1
		elif a[left] != 0 and a[right] != 0:
			left += 1
			right -= 1
			continue
		elif left == right and a[left] == 0:
			a[left] = proximo
			break
		else:
			if a[left] == 0 and a[right] == 0:
				if valLeft[left] < valRight[right]:
					a[left] = proximo
					left += 1
				elif valLeft[left] > valRight[right]:
					a[right] = proximo
					right -= 1
				elif distLeft[left] < distRight[right]:
					a[left] = proximo
					left += 1
				else:
					a[right] = proximo
					right -= 1
			elif a[left] == 0:
				a[left] = proximo
				left += 1
			else:
				a[right] = proximo
				right -= 1		


		proximo += 1

	crescendo = True
	for i in range(n-1):
		if a[i+1] <= a[i] and crescendo:
			crescendo = False
		elif a[i+1] >= a[i] and not crescendo:
			possivel = False
		
		if a[i] == 0:
			possivel = False

	if possivel:
		print(*a)
	else:
		print("*")
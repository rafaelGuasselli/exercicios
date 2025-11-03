t = int(input())
while t:
	t-=1
	
	n, k = map(int, input().split())
	numbers = list(map(int, input().split()))

	result = k//2+1
	if k == n:
		for i in range(1, n, 2):
			if numbers[i] != (i+1)//2:
				result = (i+1)//2
				break
	else:
		for i in range(1, n-k+2):
			if numbers[i] != 1:
				result = 1
				break
		result = min(result, 2)
	print(result)
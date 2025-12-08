t=int(input())

def sign(a):
	if a == 0: return 1
	return a/abs(a)

while t:
	t-=1
	n=int(input())
	s=list(map(int, input().split()))
	a=[]

	for i in s:
		if len(a) > 0 and sign(i) == sign(a[-1][0]):
			a[-1].append(i)
		else:
			a.append([i])
	
	maxSum = 0
	for i in a:
		maxSum += max(i)
	print(maxSum)
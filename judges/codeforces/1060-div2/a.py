t=int(input())
while t:
	t-=1
	n, k = map(int, input().split())
	s = input()
 
	lastOneInd = -k
	count = 0
	for i in range(n):
		if s[i] == "0": continue
		if i-lastOneInd >= k:
			count+=1
		lastOneInd=i
 
	print(count)
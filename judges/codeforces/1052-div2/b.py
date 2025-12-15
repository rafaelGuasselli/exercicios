t=int(input())
while t:
	t-=1
	n, m = map(int, input().split())
	
	freq = [0]*(m+1)
	sets=[]
	for i in range(n):
		sets.append(list(map(int, input().split())))
		for j in sets[-1][1:]:
			freq[j] += 1
	
	if min(freq[1:]) < 1:
		print("NO")
	else:
		count=0
		for i in range(n):
			pos=True
			for j in sets[i][1:]:
				freq[j] -= 1
				if freq[j] == 0:
					pos = 0

			for j in sets[i][1:]:
				freq[j] += 1
				
			if pos:
				count+=1
		print("YES" if count >= 2 else "NO")
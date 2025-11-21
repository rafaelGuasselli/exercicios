t=int(input())
while t:
	t-=1
	n=int(input())
	s=input()
	
	freq={}
	total = 0
	for i in s:
		if i not in freq:
			freq[i] = 0
		
		freq[i] += 1
		total += 1
  
	print(total-freq[s[-1]])
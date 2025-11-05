t=int(input())
while t:
	t-=1
	n, q = map(int, input().split())
	s = input()
	a = list(map(int, input().split()))	
	temB = s.count("B") > 0
	
	for i in a:
		if not temB:
			print(i)
		else:
			count = 0
			val = i
			ind = 0
			while val > 0:
				j = s[ind]
				if j == "A":
					val-=1
				else:
					val = val//2
				count+=1
				ind=(ind+1)%n
			print(count)
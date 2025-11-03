t=int(input())
while t:
	t-=1
	r0, x, d, n = map(int, input().split())
	s = input()
	
	if r0 < x:
		print(n)
	else:
		remove = 0
		for i in range(n):
			if s[i] == "1":
				r0 -= d
			else:
				remove+=1

			if r0 < x:
				ind = i
				break

		print(n-remove)
		
		
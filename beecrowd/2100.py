t = int(input())


while t:
	t-=1
	
	n, m = map(int, input().split())
	extra = n - m*2
	
	fact = 1
	for i in range(max(extra+1, 2), m+extra+1):
		fact *= i
		fact %= 1300031

	ways = (pow(2, m, 1300031) * fact)%1300031
	print(ways)
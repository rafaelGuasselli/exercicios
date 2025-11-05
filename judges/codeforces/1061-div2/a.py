from math import ceil
t=int(input())
while t:
	t-=1
	n=int(input())
	count = 0
	while n > 2:
		count += n//3
		n = n//3 + n%3
	print(count)
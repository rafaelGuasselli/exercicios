# a b c d e
# 
# [a+1, a+2, ..., 2*b-1]
# [a+1, a+2, ..., 3*c-1]
# [a+1, a+2, ..., 4*d-1]
# [f, ..., l]
# f = a+1
# l = 


t = int(input())
while t:
	t-=1
	n = int(input())
	a = list(map(int, input().split()))

	f = a[0]+1
	l = 2*a[1]-1


	print(f, l)

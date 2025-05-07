from math import sqrt
try:
	while True:
		a, b, c = map(float, input().split())
		if a<b+c and b<a+c and c<b+a:
			p = (a+b+c)/2
			area = 4/3*sqrt(p*(p-a)*(p-b)*(p-c))
			print("{:.3f}".format(area))
		else:
			print("{:.3f}".format(-1))

except EOFError:
	pass

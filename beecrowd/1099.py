def soma(a, b):
	if (a == b): 
		return 0

	a1 = min(a, b)
	an = max(a, b)

	a1 = a1 + (1 + a1 % 2)
	an = an - (1 + an % 2)

	n = (2 - a1 + an)/2
	return ((a1 + an) * n)/2

n = int(input())
while (n > 0):
	a, b = map(int, input().split())
	print("{:.0f}".format(soma(a,b)))
	n -= 1
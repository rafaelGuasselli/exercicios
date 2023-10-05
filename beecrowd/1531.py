def findPissanoPeriody(m):
	previous, current = 1, 1

	for i in range(1, m * m):
		previous, current = current, (current + previous) % m
		if previous == current and current == 1:
			return i

def fastDoublingFib(n, m):
	if n == 0:
		return (0, 1)
	else:
		a, b = fastDoublingFib(n // 2, m)
		c = (a * ((b << 1) - a))
		d = (a * a + b * b)
		print(a,b,c,d)
		if n % 2 == 0:
			return (c % m, d % m)
		else:
			return (d % m, (c + d) % m)
# 
def ex(entrada):
	n, m = map(int, entrada.split())
	periody = findPissanoPeriody(m)
	
	fib1 = int(fastDoublingFib(n, periody)[0])
	fib2 = int(fastDoublingFib(fib1, m)[0]) 
	print(fib2)

while True:
	try:
		ex(input())
	except EOFError:
		break
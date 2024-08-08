from math import floor, sqrt,ceil
def ehPrimo(n):
	for i in range(2, ceil(sqrt(n) + 1)):
		if n % i == 0:
			return False
	return True
	
n = int(input())
primos = []
for i in range(0, n):
	currentNumber = n - i
	if len(primos) >= 2 and (primos[len(primos)-2] - primos[len(primos)-1]) == 2:
		break

	if ehPrimo(currentNumber):
		primos.append(currentNumber)
	
print("{:n} {:n}".format(primos[len(primos)-1], primos[len(primos)-2]))
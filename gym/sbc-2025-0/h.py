from math import ceil, floor
n = int(input())
binN = bin(n)[2:]
binN = binN[::-1]

def toNum(binario):
	val = 0
	for i in range(len(binario)):
		val += 2**i if binario[i] == "1" else 0
	return val

if binN.count("1") == 1 and n > 1:
	print(toNum("1" * (len(binN)-1)))
else:
	result = list("1" * len(binN))
	for i in range(floor(len(binN)/2), -1, -1):
		if toNum(result) <= n:
			break

		result[i] = result[-1-i] = "0"
	
	for i in range(0, ceil(len(binN)/2)):
		result[i] = result[-1-i] = "1"

		if toNum(result) > n:
			result[i] = result[-1-i] = "0"
	
	print(toNum(result))
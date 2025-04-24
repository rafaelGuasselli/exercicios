while True:
	A, B, C, D = map(float, input().split())
	if A == 0 and B == 0 and C == 0 and D == 0:
		break

	result = C/D * (B+A/2)
	result *= 100000000
	result = round(result)
	result /= 100000000

	print("{:.5f}".format(result))
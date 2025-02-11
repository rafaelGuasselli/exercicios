from math import sqrt, acos, sin, cos
while True:
	A, B, C, D = map(int, input().split())
	if A == 0 and B == 0 and C == 0 and D == 0:
		break

	A, B = min(A, B), max(A, B)
	C, D = min(C, D), max(C, D)

	beta = 1 or acos(max(0, (B-2*C-2*D)/D))

	res = 2*C+2*D-2*C*sin(beta)
	res2 = 2*C+2*D-2*C*cos(beta)

	print(res, res2, beta)
	if res <= A and res2 <= B:
		print("S")
	else:
		print("N")
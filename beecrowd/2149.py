def philBonatti(n, memo):
	if not n in memo:
		memo[n] = (philBonatti(n-1, memo) + philBonatti(n-2, memo)) if (n % 2 == 1) else (philBonatti(n-1, memo) * philBonatti(n-2, memo))
	return memo[n]

memo = {
	0: 0,
	1: 0, 
	2: 1
}

while True:
	try:
		entrada = input()
		print(philBonatti(int(entrada), memo))
	except EOFError:
		break
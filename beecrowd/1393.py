def fib(n, memo):
	if n in memo:
		return memo[n]
	memo[n] = fib(n-1, memo) + fib(n-2, memo) 
	return memo[n]


memo = {
	0: 1,
	1: 1
}
fib(40, memo)

while True:
	entrada = input()
	if entrada == "0":
		break
	print(memo[int(entrada)])
n = int(input())

def somar(saldo, val):
	saldo[1] += val[1]
	saldo[0] += val[0] + saldo[1]//100
	saldo[1] %= 100
		
entrada = input()[1:].split(".")
saldo = list(map(int, entrada))

count = 0
for i in range(n):
	entrada = input()[1:].split(".")
	val = list(map(int, entrada))
	somar(saldo, val)

	if saldo[1] != 0:
		count += 1
print(count)
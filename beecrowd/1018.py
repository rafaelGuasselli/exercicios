n = int(input())
array = [100, 50, 20, 10, 5, 2, 1]

print(n)
for i in array:
	count = n//i
	n %= i
	print("{:d} nota(s) de R$ {:.2f}".format(count, i).replace('.', ','))
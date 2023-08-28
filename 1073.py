max = int(input())
n = 2
while n <= max:
    print("{:n}^2 = {:n}".format(n, n ** 2))
    n+=2
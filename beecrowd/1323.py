n = int(input())
while n != 0:
    print("{:n}".format((n * (n + 1) * (2 * n + 1))/6))
    n = int(input())
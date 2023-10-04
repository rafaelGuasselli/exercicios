def findPissanoPeriody(m):
    previous, current = 1, 1

    for i in range(0, m * m):
        previous, current = current, (current + previous) % m
        if previous == current and current == 1:
            return i + 1

def fastDoublingFib(n):
    if n <= 1:
        return (1, 1)
    else:
        a, b = fastDoublingFib(n // 2)
        c = a * ((b << 1) - a)
        d = a * a + b * b

        if n % 2 == 0:
            return (c, d)
        else:
            return (d, c + d)

def ex(entrada):
    n, m = map(int, entrada.split())
    periody = findPissanoPeriody(m)

    n = n % periody
    fib1 = int(fastDoublingFib(n)[0]) % periody
    fib2 = int(fastDoublingFib(fib1)[0]) % periody
    print(fib2)

while True:
    try:
        ex(input())
    except EOFError:
        break
def eofInput():
    try:
        return input()
    except EOFError:
        return False

entrada = eofInput()
while (entrada):
    v, t = map(int, entrada.split())
    d = 0
    if (t > 0):
        a = v/t
        d = a * ((t * 2) ** 2)/2
    print("{:.0f}".format(d))
    entrada = eofInput()
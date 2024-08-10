n = int(input())
while(n > 0):
    current = int(input())
    even = current % 2 == 0
    positive = current > 0
    zero = current == 0

    if zero:
        print("NULL")
    else:
        message = ""
        message += "EVEN" if even else "ODD"
        message += " POSITIVE" if positive else " NEGATIVE"
        print(message)

    n-=1
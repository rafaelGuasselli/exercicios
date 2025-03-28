from math import floor;
while True:
    x, y = map(int, input().split())
    amountOfCarries = 0
    if x == 0 and y == 0:
        break

    extra = 0
    while (x > 0 or y > 0):
        mod_x = x % 10
        mod_y = y % 10
        if (mod_x + mod_y + extra >= 10): 
            amountOfCarries += 1
        extra = floor((mod_x + mod_y + extra)/10)
        x = floor(x/10)
        y = floor(y/10)
    if (amountOfCarries == 0):
        print("No carry operation.")
    elif amountOfCarries == 1:
        print("1 carry operation.")
    else:
        print("{:n} carry operations.".format(amountOfCarries))
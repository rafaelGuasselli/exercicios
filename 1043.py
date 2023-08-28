a, b, c = map(float, input().split())

ac = (b-c) < a and a < (b + c)
bc = (a-c) < b and b < (a + c)
cc = (a-b) < c and c < (a + b)
    
if ac and bc and cc:
    print("Perimetro = {:.1f}".format(a+b+c))
else:
    print("Area = {:.1f}".format((a+b)*c/2))  
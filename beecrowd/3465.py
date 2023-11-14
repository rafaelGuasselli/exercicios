x = input()
a, b, c = map(int, x.split())
p = (a+b+c)/2
r = (p*(p-a)*(p-b)*(p-c))**(1/2)
print(f'{r:.3f} m2')
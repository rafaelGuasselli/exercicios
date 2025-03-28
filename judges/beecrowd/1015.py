from math import sqrt

point1 = input().split()
point2 = input().split()

x1 = float(point1[0])
y1 = float(point1[1])
x2 = float(point2[0])
y2 = float(point2[1])

print("{:.4f}".format(sqrt(pow(x2-x1, 2)+pow(y2-y1, 2))))
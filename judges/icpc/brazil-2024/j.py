from math import tan, radians
alpha, n = map(int, input().split())
ranges = []

for i in range(n):
	x, h = map(int, input().split())
	left = min(x, x+h/tan(radians(alpha)))
	right = max(x, x+h/tan(radians(alpha)))
	ranges.append((left, right))


ranges.sort()

total = 0
prevInit = ranges[0][0]
prevEnd = ranges[0][1]
for r in ranges:
	if r[0] > prevEnd:
		total += prevEnd-prevInit
		prevInit = r[0]
		prevEnd = r[1]
	else:
		prevEnd = max(r[1], prevEnd)

total += prevEnd-prevInit
print("{:.15f}".format(total))
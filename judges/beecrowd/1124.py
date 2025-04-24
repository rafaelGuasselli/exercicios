from math import sqrt
while True:
	w, h, r, R = map(int, input().split())
	if w == h == r == R == 0:
		break

	pos1 = (r, r)
	pos2 = (w - R, h - R)

	dist = sqrt((pos1[0] - pos2[0])**2 + (pos1[1] - pos2[1])**2)
	if dist >= r + R and 2*r <= w and 2*r <= h and 2*R <= w and 2*R <= h:
		print('S')
	else:
		print('N')

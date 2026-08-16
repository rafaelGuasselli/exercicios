t = int(input())
while t:
	t-=1
	n, k = map(int, input().split())
	s = input()
	ts = list(s)


	points = [0, 0]

	for i in range(2*n):
		ti = i+1 if i+1 < 2*n else 0
		if s[i] == "1" and s[ti] == "0":
			ts[i] = "0"
			ts[ti] = "1"

	for i in range(2 * n):
		if ts[i] == "1":
			points[(i+1)%2] += 1

	print(*points)
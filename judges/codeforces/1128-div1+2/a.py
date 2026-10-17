t = int(input())
while t:
	t-=1
	n = int(input())
	s = input()

	smallestOne = 1e9
	biggeestOne = 0
	countOne = s.count("1")
	for i in range(len(s)):
		if s[i] == "1":
			smallestOne = min(smallestOne, i+1)
			biggeestOne = max(biggeestOne, i+1)

	if countOne == 1:
		print(0)
	elif countOne == 2:
		print(1)
	else:
		print(biggeestOne-smallestOne)
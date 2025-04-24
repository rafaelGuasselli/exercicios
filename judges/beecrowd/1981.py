modulo = 100000007
factorial = [1] * 10010
for i in range(2, 10010):
	factorial[i] = (factorial[i-1]*i)

while True:
	try:
		s = input()
		if s == "0":
			break

		chars = [0] * 30
		for c in s:
			chars[ord(c)-ord('a')] += 1
			
		total = factorial[len(s)]
		for i in range(0, 30):
			total = total//factorial[chars[i]]

		print(int(total)%modulo)
	except EOFError:
		break

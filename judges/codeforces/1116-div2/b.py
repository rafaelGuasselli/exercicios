import sys
input = lambda: sys.stdin.readline().rstrip('\r\n')

def check(s, os):
	for i in range(len(s)):
		if i >= 2 and s[i] == s[i-2]:
			return False

		if os[i] == "?": continue
		if s[i] != os[i]:
			return False
	
	return True

def generateAlt(l, o):
	s = ["0"] * l
	for i in range(l):
		s[i] = str(int(((i+o)//2)%2))

	return "".join(s)

def generate(sc, ec, o,  l):
	return str(sc) + generateAlt(l-2, o) + str(ec)

t = int(input())
while t:
	t-=1
	n = int(input())
	s = input()

	p = set([
		generate(0, 0, 1, len(s)), # 0011 0
	    generate(0, 1, 1, len(s)), # 0011 1
	    generate(1, 0, 3, len(s)), # 1100 0
		generate(1, 1, 3, len(s)), # 1100 1
	
		generate(1, 0, 0, len(s)), # 1 0011 0
		generate(1, 1, 0, len(s)), # 1 0011 1

		generate(0, 0, 2, len(s)), # 0 1100 0
		generate(0, 1, 2, len(s)), # 0 1100 1
	])

	p2 = []
	for i in p:
		if check(i, s):
			p2.append(i)

	print(len(p2))
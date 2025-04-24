t = int(input())

def getVal(ind, s):
	if ind < 0 or ind >= len(s):
		return		
	return s[ind]
	
while True:
	if t == 0:
		break
	t -= 1
	s = list(input())
	q = int(input())


	pos = [0] * (len(s) + 20)
	total  = 0
	for i in range(0, len(s)):
		if getVal(i, s) == "1" and getVal(i+1, s) == "1" and getVal(i+2, s) == "0" and getVal(i+3, s) == "0":
			pos[i] = 1
			total += 1


	for i in range(0, q):
		ind, val = map(int, input().split())
		ind -= 1
		s[ind] = str(val)
		
		for j in range(0, 7):
			if getVal(ind-3+j, pos) == 1:
				pos[ind-3+j] = 0
				total -= 1

		for j in range(0, 7):
			if getVal(ind-3+j, s) == "1" and getVal(ind-2+j, s) == "1" and getVal(ind-1+j, s) == "0" and getVal(ind+j, s) == "0":
				pos[ind-3+j] = 1
				total += 1

		if total > 0:
			print("YES")
		else:
			print("NO")

			

t=int(input())
while t:
	t-=1
	s=input()

	if s.find("**") != -1:
		print(-1)
	elif s.find("*<") != -1:
		print(-1)
	elif s.find(">*") != -1:
		print(-1)
	elif s.find(">") < s.find("<", s.find(">") ) and s.find(">") != -1:
		print(-1)
	else:
		left=0
		right=0

		for i in s:
			if i == "<":
				left+=1
			elif i == "*":
				left+=1
				break
			else:
				break
		
		s = s[::-1]
		for i in s:
			if i == ">":
				right+=1
			elif i == "*":
				right+=1
				break
			else:
				break
		
		print(max(left, right))
		

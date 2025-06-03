entrada = input().split()
k = int(entrada[0])
s = list(entrada[1])

if k == 2:
	val = 0
	mod1 = 0
	s1 = list(s)
	s2 = list(s)
	
	for i in range(len(s1)):
		if s1[i] != str(val):
			s1[i] = str(val)
			mod1 += 1
		val = (val+1)%2

	val = 1
	mod2 = 0

	for i in range(len(s2)):
		if s2[i] != str(val):
			s2[i] = str(val)
			mod2 += 1
		val = (val+1)%2

	if mod1 <= mod2:
		print(f"{mod1} {''.join(s1)}")
	else:
		print(f"{mod2} {''.join(s2)}")

else:
	countModTotal = 0
	count = 0
	for i in range(len(s)):
		count = count+1 if s[i]==s[i-1] else 1
		if count == k:
			count = 1
			countModTotal+=1
			if i != len(s)-1 and s[i] == s[i+1]:
				s[i] = str((int(s[i])+1)%2)
			else:
				s[i-1] = str((int(s[i])+1)%2)

	print(countModTotal, end=" ")
	print("".join(s))
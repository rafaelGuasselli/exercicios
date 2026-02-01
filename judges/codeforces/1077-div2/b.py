from math import ceil
t=int(input())
while t:
	t-=1
	n=int(input())
	s=input()

	acc=[]
	count=0
	firstOne = 0
	for i in range(n):
		if s[i] == "1" and count > 1:
			acc.append(count-1-firstOne)
			count=0
			firstOne = 1
		elif s[i] == "1":
			firstOne = 1
			count=0
		if s[i] == "0":
			count+=1

	if count > 0:
		acc.append(count-firstOne)

	total = s.count("1")
	for i in acc:
		total += ceil(i/3)
	print(total)
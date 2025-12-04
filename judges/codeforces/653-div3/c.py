t=int(input())
while t:
	t-=1
	n=int(input())
	s=input()
	balance=0
	count=0
	for i in s:
		if i == "(":
			balance+=1
		else:
			balance-=1
		
		if balance < 0:
			count+=1
			balance = 0
	print(count)
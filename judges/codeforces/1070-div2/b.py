t=int(input())
while t:
	t-=1
	n=int(input())
	bina=input()

	zeros=[]
	count=0
	ones=0
	for i in bina:
		if i == "0":
			count+=1
		elif count > 0:
			zeros.append(count)
			count=0
			ones+=1
	if count>0 and bina[0] == "0":
		zeros[0] += count
	elif count > 0:
		zeros.append(count)
		ones+=1

	desc=0
	total=bina.count("0")
	zeros.sort()
	cost=0
	for i in zeros:
		total-=ones*(i-desc)
		cost+=i-desc
		desc = i
		ones-=1
	
	cost+=total
	print(cost)
	

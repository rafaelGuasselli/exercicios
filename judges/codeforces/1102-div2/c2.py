# def allocateOnEmptyTable():
# 	#print("allocate empty")
# 	global nEmptyTables, nNonEmptySits, total, introvertsLeft


# def allocateOnFilledTable():
# 	#print("allocate filled")
# 	global nNonEmptySits, total
# 	nNonEmptySits -= 1
# 	total += 1
#2 4
#AAAAAIEE


t=int(input())
while t:
	t-=1
	nFren, nTables, nSits = map(int, input().split())
	s = input()


	def countTotal(nTables, nSits, AICount, s):
		total=0
		ambCount = 0
		nNonEmptySits = 0
		for i in s:
			if i == "A":
				i = "I" if ambCount < AICount else "E"
				ambCount+=1
			if i == "I" and nTables > 0:
				nTables-= 1
				nNonEmptySits+=nSits-1
				total+=1
			if i == "E" and nNonEmptySits > 0:
				nNonEmptySits-=1
				total+=1
		return total

	left=0
	right=s.count("A")+1
	total = 0

	while left<=right:
		middle1 = left + (right-left)//3
		middle2 = left + 2*(right-left)//3
		cm1 = countTotal(nTables, nSits, middle1, s)
		cm2 = countTotal(nTables, nSits, middle2, s)
		total = max(total, cm1, cm2)

		if cm1 == cm2:
			left = middle1+1
			right = middle2-1
		elif cm1 < cm2:
			left = middle1+1
		else: 
			right = middle2-1

	print(total)
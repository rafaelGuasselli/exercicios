def isOdd(n):
	return not isEven(n)

def isEven(n):
	return n%2==0


t = int(input())
while t:
	t-=1
	n = int(input())
	a = list(map(int,input().split()))

	par=0
	imp=0
	for i in a:
		if i%2==0:
			par+=1
		else:
			imp+=1
	total = par >= 1


	if n == 1:
		print("Moggity")
	elif isEven(imp):
		print("Moggity")
	elif par == 1 and imp == 1:
		print("Larpity")
	elif par == 0 and imp == 3:
		print("Larpity")
	elif par == 0 and imp > 3:
		print("Moggity")
	elif par > 0 and imp == 1:
		print("Moggity")
	elif par > 0 and imp == 3:
		print("Moggity")
	elif par > 0 and imp > 3:
		print("Moggity")

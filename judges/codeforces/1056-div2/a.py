from math import ceil, floor
t=int(input())
while t:
	t-=1
	n=int(input())

	count=1
	win=n
	los=0
	
	while win>1 or los>1:
		count+=floor(los/2)+floor(win/2)
		los=ceil(los/2)
		los+=floor(win/2)
		win=ceil(win/2)

	print(count)

	
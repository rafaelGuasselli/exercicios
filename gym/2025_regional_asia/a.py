a=list(map(int, input().split()))
a.sort()
if a[-1]-10>=a[0]:
	print("check again")
else:
	print("final {:d}".format(a[1]))
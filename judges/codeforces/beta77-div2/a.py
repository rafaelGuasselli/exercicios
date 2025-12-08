s=input()
prev=-1
count=0
dang=0
for i in s:
	if prev != i:
		if count>=7: dang=1
		count=0
	count+=1
	prev=i
if count>=7: dang=1
if dang:
	print("YES")
else:
	print("NO")
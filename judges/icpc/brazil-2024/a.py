s = input()
a = list(s)
a.sort()

count = 0
index = 0
for i in s:
	if i == a[0]:
		count += 1
	if count == s.count(a[0]):
		print(index)
		break
	index += 1
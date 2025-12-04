d, s = map(int, input().split())

if d > 1 and s == 0:
	print("-1 -1")
elif d*9 < s:
	print("-1 -1")
else:
	menor = [0] * d
	maior = [0] * d


	menor[0] = maior[0] = 1
	countMaior = s-1
	for i in range(d):
		target = min(countMaior+maior[i], 9)
		change = target-maior[i]
		maior[i] = target
		countMaior-=change
		if countMaior <= 0:
			break


	countMenor = s-1
	for i in range(d):
		target = min(countMenor+menor[-i-1], 9)
		change = target-menor[-i-1]
		menor[-i-1] = target
		countMenor-=change
		if countMenor <= 0:
			break
	

	for i in menor:
		print(i, end="")
	print(" ", end="")

	for i in maior:
		print(i, end="")
	print()
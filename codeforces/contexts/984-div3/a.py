t = int(input())
while True:
	if t == 0:
		break
	t -= 1
	n = int(input())
	notas = list(map(int, input().split()))
	falha = 0
	for i in range(1, n):
		semitones = abs(notas[i]-notas[i-1])
		if (semitones != 5 and semitones != 7):
			falha = 1
			break
	
	if falha:
		print("NO")
	else:
		print("YES")
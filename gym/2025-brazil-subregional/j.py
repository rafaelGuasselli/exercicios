l = list(map(int, input().split()))

freq = [0] * 5
for i in l:
	freq[i] += 1

count = 0
for i in freq: 
	if i == 0: count+=1

print(count-1)
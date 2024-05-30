from math import ceil
size = int(input())
word = input()
marked = [False for i in range(size)]

palindromes = 0
for i in range(size, 0, -1):
	for j in range(0, size-i+1):
		firstHalf = word[j : j+ceil(i/2)]
		lastHalf = word[j+i//2 : j+i]

		print(firstHalf + " " + lastHalf[::-1])

		if firstHalf == lastHalf[::-1] and not marked[j] and not marked[j+i-1]:
			palindromes += 1
			for w in range(j, j+i):
				marked[w] = True

for i in range(0, size):
	print(marked[i])  

print(palindromes)
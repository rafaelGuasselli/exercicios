from math import log2

def isPowerOf2(val):
	return int(log2(val)) == log2(val)

n = int(input())
a = list(map(int, input().split()))
mapa = [0] * 200000


for i in a:
	mapa[i] += 1

ma = max(a)
count = 0

for i in range(ma):
	mapa[i+1] += mapa[i]//2
	mapa[i] %= 2
	if mapa[i] == 1:
		count += 1

nonEmpty = []
for i in range(len(mapa)):
	if mapa[i] > 0:
		nonEmpty.append(i)

if len(nonEmpty) > 2 or n == 1:
	print("N")
elif len(nonEmpty) == 2 and isPowerOf2(mapa[nonEmpty[0]]) and isPowerOf2(mapa[nonEmpty[1]]):
	print("Y")
elif len(nonEmpty) == 1 and isPowerOf2(mapa[nonEmpty[0]]):
	print("Y")
else:
	print("N")
from multiset import Multiset
import heapq
from bisect import bisect_left
t=int(input())
while t:
	t-=1
	n, m = map(int, input().split())
	swords=Multiset(list(map(int, input().split())))
	mosters=list(map(int, input().split()))
	replaces=list(map(int, input().split()))
	
	regain=[]
	normal=[]
	
	for i in range(m):
		if replaces[i] > 0:
			regain.append((mosters[i], replaces[i]))
		else:
			normal.append(mosters[i])

	
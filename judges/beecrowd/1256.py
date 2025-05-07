n = int(input())
while n:
	n-=1

	s, m = map(int, input().split())
	memoria = [[] for i in range(s)]
	entrada = list(map(int, input().split()))

	for i in entrada:
		memoria[i%s].append(i)
	
	for i in range(s):
		print(f"{i} -> ", end="")

		for j in memoria[i]:
			print(f"{j} -> ", end="")

		print("\\")
	if n > 0: print()
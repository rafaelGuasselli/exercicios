import sys

def pprint(va):
	print(va)
	sys.stdout.flush()
	

t=int(input())
while t:
	t-=1
	n = int(input())

	pprint(f"? {1} {n}")
	total = int(input())

	if total == n or total == 0:
		pprint("! NO")
		continue

	pprint(f"? {1+total} {n}")
	val = int(input())

	if val > 0:
		pprint("! YES")
		continue
	else:
		pprint("! NO")
		continue
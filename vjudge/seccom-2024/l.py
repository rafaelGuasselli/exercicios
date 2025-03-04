from math import gcd
t = int(input())
cases = 1
for _ in range(t):
	a, b, c = map(int, input().split())
	if(c%gcd(a, b) == 0):
		print(f"Case {cases}: Yes")
	else:
		print(f"Case {cases}: No")
	cases+=1;	
modulo = 998244353
f = [1]*1000010
inv = [1]*1000010

for i in range(1, 1000010):
	f[i] = (f[i-1] * i)%modulo


inv[1000009] = pow(f[1000009], modulo - 2, modulo)
for i in range(1000008, 0, -1):
	inv[i] = (i * inv[i+1])%modulo


t = int(input())
while t:
	t-=1
	n = int(input())
	s = input()

	z = s.count("0")
	o = s.count("1")
	total = (f[z+o] * inv[z] * inv[o]) % modulo

	print(total)


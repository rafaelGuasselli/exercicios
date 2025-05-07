n = int(input())
times = []
for i in range(n):
	entrada = input().split()
	nome = entrada[0]
	trampolim = list(map(int, entrada[2:]))
	programacao = 10 * int(entrada[1])
	trampolim.sort()
	pontuacao = programacao + sum(trampolim[1:-1])

	times.append((-pontuacao, i, nome))
times.sort()

ind = 0
count = 0
previous = -1e9
while ind < min(n, 1000):
	pont, i, nome = times[ind]
	pont = -pont


	if pont < previous and count >= 3:
		break

	print(f"{nome} {pont}")
	count += 1
	previous = pont
	ind += 1
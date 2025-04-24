from functools import reduce
numeroJogadores, numeroPartidas = map(int, input().split())
total = 0

for i in range(0, numeroJogadores):
	desempenhoJogador = list(map(int, input().split()))
	total += reduce(lambda a,b: min(b, 1) * min(a, 1), desempenhoJogador)
print(total)
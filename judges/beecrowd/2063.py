from math import lcm, gcd
def dfs(tunel, tuneis, profundidade):
	if tunel == -1:
		return profundidade - 1
	proximo, tuneis[tunel-1] = tuneis[tunel-1], -1
	return dfs(proximo, tuneis, profundidade + 1)

qtdBuracos = int(input())
tuneis = list(map(int, input().split()))
tamanhoDosCiclos = []

for i in range(0, qtdBuracos):
	if tuneis[i] != -1:
		profundidade = dfs(i+1, tuneis, 0)
		if profundidade != 0:
			tamanhoDosCiclos.append(profundidade)

mmc = 1
for tamanho in tamanhoDosCiclos:
	mmc = lcm(mmc, tamanho)
print(mmc)
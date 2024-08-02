qtdDeuses = int(input())
ranking = []
for i in range(0, qtdDeuses):
	deus, poder, qtdMatou, qtdMorreu = input().split()
	poder, qtdMatou, qtdMorreu = map(int, (poder, qtdMatou, qtdMorreu))
	ranking.append((-poder, -qtdMatou, qtdMorreu, deus))
ranking.sort(reverse=False)
print(ranking[0][3])
n, m, qtdSoldado = map(int, input().split())

segundoExercito = 0
primeiroExercito = 0

for i in range(0, qtdSoldado):
	x, y, poder = map(int, input().split())
	#Acha a equação que gera a linha diagonal
	#Verifica se está abaixo ou acima
	#Ref:
	#https://math.stackexchange.com/questions/324589/detecting-whether-a-point-is-above-or-below-a-slope
	if (y > (m/n * x)):
		primeiroExercito += poder
	else:
		segundoExercito += poder
print("{:n} {:n}".format(primeiroExercito, segundoExercito))
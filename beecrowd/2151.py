
def ex():
	alturaParede, larguraParede, ySoco, xSoco = map(int, input().split())
	paredes = []
	for i in range(0, alturaParede):
		paredes.append(list(map(int, input().split())))
	
	impacto = []



qtdTestes = int(input())
for i in range(0, qtdTestes):
	print("Parede {:n}:".format(i+1))
	ex()

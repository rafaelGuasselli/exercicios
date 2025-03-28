import heapq
	
def ex():
	danoAndre, esperaAndre, danoBeto, esperaBeto  = list(map(int, input().split()))
	vidaMonstro = int(input())

	ordemAtaques = [[0, "Andre", esperaAndre, danoAndre], [0, "Beto", esperaBeto, danoBeto]]
	ultimoAtacante = "Andre"

	while(vidaMonstro > 0):
		tempoRestante, nome, tempoTotal, dano = heapq.heappop(ordemAtaques)
		
		vidaMonstro -= dano
		ultimoAtacante = nome
		ordemAtaques[0][0] -= tempoRestante
		
		heapq.heappush(ordemAtaques, [tempoTotal, nome, tempoTotal, dano])
	print(ultimoAtacante)

qtdTestes = int(input())
for i in range(qtdTestes):
	ex()
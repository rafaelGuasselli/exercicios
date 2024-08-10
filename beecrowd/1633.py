import io, os, sys, heapq
input = io.BytesIO(os.read(0,os.fstat(0).st_size)).readline

def ex(entrada):
	qtdProcessos = int(entrada)
	processos = []

	for i in range(qtdProcessos):
		tempoDaRequisicao, tempoDeExecucao = map(int, input().split())
		processos.append((tempoDaRequisicao, tempoDeExecucao))
	
	processos.sort(reverse=True)

	total = 0
	tempoAtual = 1
	proximosAExecutar = []

	while len(processos) > 0 or len(proximosAExecutar) > 0:
		while len(processos) > 0 and processos[-1][0] <= tempoAtual:
			tempoDaRequisicao, tempoDeExecucao = processos.pop()
			heapq.heappush(proximosAExecutar, (tempoDeExecucao, tempoDaRequisicao))

		if len(proximosAExecutar) == 0:
			tempoDaRequisicao, tempoDeExecucao = processos.pop()
			heapq.heappush(proximosAExecutar, (tempoDeExecucao, tempoDaRequisicao))

		tempoDeExecucao, tempoDaRequisicao = heapq.heappop(proximosAExecutar)
		tempoEspera = max(tempoAtual - tempoDaRequisicao, 0)
		total += tempoEspera
		tempoAtual = tempoDaRequisicao + tempoEspera + tempoDeExecucao

	sys.stdout.write(str(total) + "\n")

if __name__ == "__main__":
	while True:
		try:
			entrada = input()
			ex(entrada)
		except:
			break
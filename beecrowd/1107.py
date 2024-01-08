import heapq

def findAmountOfGaps(array):
	lastIndex = 0
	gaps = 0
	for element in array:
		value, index = element
		if abs(lastIndex-index) > 1:
			gaps += 1
		lastIndex = index
	return gaps

def ex(entrada):
	altura, comprimento = map(int, entrada.split())
	alturaDosBlocos = list(map(int, input().split()))
	heap = []
	qtdLaser = 0

	for i in range(0, comprimento):
		heapq.heappush(heap, (-alturaDosBlocos[i], i))

	ultimaAltura = altura
	while (len(heap) > 0):
		bloco = altura, index = heapq.heappop(heap)
		layer = [bloco]

		while len(heap) > 0 and altura == heap[0][0]:
			layer.append(heapq.heappop(heap))
		print(layer)
		print(altura, ultimaAltura)

		qtdLaser += findAmountOfGaps(layer) + (ultimaAltura + altura)
		ultimaAltura = -altura - 1 
	print(qtdLaser)



while True:
	entrada = input()
	if entrada == "0 0":
		break
	
	ex(entrada)
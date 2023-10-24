from collections import OrderedDict

def ex():
	frequencia = {}
	totalDeArvores = 0
	
	while True:
		arvore = inputEof()
		if not arvore or arvore.strip() == "": 
			break
		if not arvore in frequencia:
			frequencia[arvore] = 0
		frequencia[arvore] += 1
		totalDeArvores += 1

	frequencia = OrderedDict(sorted(frequencia.items(), key=lambda a:a[0].lower()))
	for arvore in frequencia:
		print("{:s} {:.4f}".format(arvore, 100 * frequencia.get(arvore)/totalDeArvores))
	

def inputEof():
	try:
		return input()
	except EOFError:
		return False
	
numCasosTeste = int(input())
empty_line = inputEof()
for i in range(0, numCasosTeste):
	ex()
	if i < numCasosTeste-1:
		print()
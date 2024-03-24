from functools import reduce

def ex():
	qtdRodadas = int(input())

	contarCartas = {}
	cartasJohn = list(map(int, input().split()))
	cartasMary = list(map(int, input().split()))
	cartasComuns = list(map(int, input().split()))

	for carta in cartasJohn+cartasMary+cartasComuns:
		if not carta in contarCartas:
			contarCartas[carta] = 0
		contarCartas[carta] += 1

	totalPontosJohn = reduce(lambda a, b: a+min(10, b), cartasJohn[1:]+cartasComuns, min(10, cartasJohn[0]))
	totalPontosMary = reduce(lambda a, b: a+min(10, b), cartasMary[1:]+cartasComuns, min(10, cartasMary[0]))

	
	cartaFaltando = 23 - totalPontosMary
	cartaQuebra = 24 - totalPontosJohn

	for carta in range(cartaQuebra, cartaFaltando):
		if (not carta in contarCartas or contarCartas[carta] < 4) and carta <= 10:
			print(carta)
			return

	if (not cartaFaltando in contarCartas or contarCartas[cartaFaltando] < 4) and cartaFaltando <= 10:
		print(cartaFaltando)
		return

	
	print("-1")

ex()
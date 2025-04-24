def ex2366(numeroPostosDeAgua, posicoesPostoDagua):
	posicoesPostoDagua.append(42195)

	for i in range(1, numeroPostosDeAgua+1):
		diferenca = posicoesPostoDagua[i] - posicoesPostoDagua[i-1]
		if diferenca > distanciaIntermediaria:
			print("N")
			return
	print("S")

numeroPostosDeAgua, distanciaIntermediaria = map(int, input().split())
posicoesPostoDagua = list(map(int, input().split()))
ex2366(numeroPostosDeAgua, posicoesPostoDagua)
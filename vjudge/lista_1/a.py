def id(palavra):
	palavra = palavra.rstrip(" ")
	palavra = list(palavra)

	palavra.sort()
	palavra = "".join(palavra)

	return hash(palavra)

def somaSequencia(x, y):    
    if x == y: return 0
    
    menor = min(x, y)
    maior = max(x, y)
    tamanhoDoRange = (maior - menor  + 1)/2
    return int((menor + maior) * tamanhoDoRange)

def ex():
	qtdLinhas, qtdColunas = map(int, input().split())
	matrix = []
	celulasEspeciais = [[] for i in range(qtdLinhas)]
	linhas = ""
	colunas = ""
	diagonais1 = ""
	diagonais2 = "" 

	testDiagonais = list(" " * (qtdColunas*qtdLinhas))

	diagonais1Array = [[] for i in range(qtdColunas+qtdLinhas-1)]
	diagonais2Array = [[] for i in range(qtdColunas+qtdLinhas-1)]

	for i in range(qtdLinhas):
		linha = input()
		matrix.append(linha)
		linhas += linha
	
	for c in range(qtdColunas):
		for l in range(qtdLinhas):
			colunas += matrix[l][c]

	#(0, a) -> (1, a+1)

	#(0,0)(0,1)(0,2)
	#(1,0)(1,1)(1,2)
	#(2,0)(2,1)(2,2)

	for l in range(qtdLinhas):
		for c in range(qtdColunas):
			middleDiagonal = (qtdColunas+qtdLinhas) // 2
			
			currentDiag = c+l+1
			distanceFromMiddle = abs(middleDiagonal-currentDiag)
			diagLength = min(middleDiagonal - distanceFromMiddle, qtdLinhas, qtdColunas)


			amountInPreviousDiags = somaSequencia(0, currentDiag-1)  
			print(amountInPreviousDiags+l-1)
			testDiagonais[amountInPreviousDiags+l-1] = matrix[l][c]
			
			diagonais1Array[c+l].append(matrix[l][c])
			diagonais2Array[c-l+qtdLinhas-1].append(matrix[l][c])


	for i in range(qtdColunas+qtdLinhas-1):
		diagonais1 += "".join(diagonais1Array[i])
		diagonais2 += "".join(diagonais2Array[i])

	
	print(linhas)
	print(colunas)
	print(diagonais1)
	print("".join(testDiagonais))
	print(diagonais2)

	# (0, 0)(0, 1)(0, 2)
	# (1, 0)(1, 1)(1, 2)
	# (2, 0)(2, 1)(2, 2)

	# (0)(1)(2)
	# (1)(2)(3)
	# (2)(3)(4)

	# (0)(1)(3)
	# (2)(4)(6)
	# (5)(7)(8)

	

	return
	qtdAnagramas = int(input())
	anagramas = []
	
	for i in range(qtdAnagramas):
		anagrama = input()
		anagramas.append(anagrama)

	
	print(count)

ex()
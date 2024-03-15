conversao = {
	"W": 64,
	"H": 32,
	"Q": 16,
	"E": 8, 
	"S": 4,
	"T": 2,
	"X": 1
}

def ex(entrada):
	partitura = entrada.split("/")[1:]
	total = 0
	for notas in partitura:
		soma = 0
		for nota in notas:
			soma += conversao[nota]
		total += 1 if soma == 64 else 0
	print(total)


while True:
	entrada = input()
	if entrada == "*":
		break
	ex(entrada)
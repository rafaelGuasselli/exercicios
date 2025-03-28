def ex(entrada):
	digito2Braille = {
		"0": [".*", "**", ".."],
		"1": ["*.", "..", ".."],
		"2": ["*.", "*.", ".."],
		"3": ["**", "..", ".."],
		"4": ["**", ".*", ".."],
		"5": ["*.", ".*", ".."],
		"6": ["**", "*.", ".."],
		"7": ["**", "**", ".."],
		"8": ["*.", "**", ".."],
		"9": [".*", "*.", ".."]
	}

	braille2Digito = {
		"*.": {
			"..": 1,
			"*.": 2,
			".*": 5,
			"**": 8
		},
		".*":{
			"*.": 9,
			"**": 0
		},
		"**": {
			"..": 3,
			"*.": 6,
			".*": 4,
			"**": 7
		}
	}

	qtdDigitos = int(entrada)
	modo = input()

	if modo == "S":
		digitos = input()

		for i in range(3):
			for j in range(0, qtdDigitos):
				digito = digitos[j]
				print(digito2Braille[digito][i], end=" " if j + 1 < qtdDigitos else "\n")
	else:
		brailleA = input().split()
		brailleB = input().split()
		brailleC = input().split()
		
		for i in range(qtdDigitos):
			top = brailleA[i]
			middle = brailleB[i]
			
			digito = braille2Digito[top][middle]
			print(digito, end="" if i + 1 < qtdDigitos else "\n")

while True:
	entrada = input()
	if entrada == "0":
		break
	ex(entrada)
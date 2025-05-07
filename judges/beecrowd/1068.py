import re
while True:
	try:
		entrada = input()
		entrada = re.sub("[^()]+", "", entrada)
		count = 0
		balanciado = True

		for i in entrada:
			if i == "(":
				count += 1
			else:
				count -= 1
				if count < 0:
					balanciado = False
		
		if count > 0 or not balanciado:
			print("incorrect")
		else:
			print("correct")
	except EOFError:
		break
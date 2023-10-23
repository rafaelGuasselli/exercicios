def ex(entrada):
	print(entrada)

def getInput():
	lines = []
	while True:
		user_input = raw_input()
		if user_input.strip() == "": 
			ex(lines)
			break
		lines.append(user_input)

numCasosTeste = int(input())
empty_line = raw_input()
for i in range(0, numCasosTeste):
	getInput()
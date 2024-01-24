numero = int(input())

string = ""
numeraisRomanos = ["CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"]
pontosCriticos =  [900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1]

while numero > 0:
	for i in range(0, len(pontosCriticos)):
		if numero >= pontosCriticos[i]:
			numero -= pontosCriticos[i]
			string += numeraisRomanos[i]
			break

print(string)
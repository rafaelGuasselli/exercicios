def ex():
	a, b = map(int, input().split())

	string = ""
	for i in range(a, b+1):
		string += str(i)
	print(string + string[::-1])

numCasosTeste = int(input())
for i in range(0, numCasosTeste):
	ex()